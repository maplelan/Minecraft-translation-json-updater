//---------------------------------------------------------------------------
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include <algorithm>
#pragma hdrstop
using namespace std;
//---------------------------------------------------------------------------
//UTF8ToGB(輸出.c_str()).c_str()
string UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;

	//獲得臨時變數的大小
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//獲得臨時變數的大小
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
//---------------------------------------------------------------------------
//GetName(檔案路徑,是否含有附檔名(預設有))
string GetName(string filepath,bool Extension=true){
  string filename=filepath;
  const size_t last_slash_idx = filename.find_last_of("\\/");
  if (std::string::npos != last_slash_idx)
  {
      filename.erase(0, last_slash_idx + 1);
  }
  // 移除附檔名
  if(!Extension){
    const size_t period_idx = filename.rfind('.');
    if (std::string::npos != period_idx)
    {
        filename.erase(period_idx);
    }
  }
  return filename;
}
//---------------------------------------------------------------------------
#pragma argsused
int main(int argc, char* argv[])
{
    cout<<"將舊版文件拖曳進視窗或直接輸入檔案路徑並按下Enter:\n(Drag the old version file into the window or enter the file path and press Enter.):"<<endl;
    string openzh="";
    getline(cin,openzh);
    openzh.erase(std::remove(openzh.begin(), openzh.end(), '"'), openzh.end());
    fstream fpzh;
    fpzh.open(openzh.c_str(),ios::in);
    if(fpzh){
      cout<<"成功\開啟"<<GetName(openzh)<<"\n(Open "<<GetName(openzh)<<" success)"<<endl<<endl;
      cout<<"將新版文件拖曳進視窗或直接輸入檔案路徑並按下Enter:\n(Drag the new version file into the window or enter the file path and press Enter.):"<<endl;
      string openen="";
      getline(cin,openen);
      openen.erase(std::remove(openen.begin(), openen.end(), '"'), openen.end());
      fstream fpen;
      fpen.open(openen.c_str(),ios::in);
      if(fpen){
        cout<<"成功\開啟"<<GetName(openen)<<"\n(Open "<<GetName(openen)<<" success)"<<endl<<endl;
        cout<<"將最終輸出文件拖曳進視窗或直接輸入檔案路徑並按下Enter 如果文件中有內容將會被覆蓋\ 如果無文件會自行建立:\n(Drag the output file into the window or enter the file path and press Enter. If there is content in the file, it will be overwritten. If there is no file, it will be created.):"<<endl;
        string openout="";
        getline(cin,openout);
        openout.erase(std::remove(openout.begin(), openout.end(), '"'), openout.end());
        fstream fpout;
        fpout.open(openout.c_str(),ios::out|ios::trunc);
        if(fpout){
          cout<<"開啟或建立"<<GetName(openout)<<"成功\\n(Open or created "<<GetName(openout)<<" success)"<<endl<<endl;
          string datazh,dataen;
          int countall=1;
          while (std::getline(fpen,dataen)){
            bool finded=false;
            while(std::getline(fpzh,datazh)){
              bool same=true;
              for(int i=0;i<dataen.size();i++){
                string colon=":";
                if(dataen[i]==colon[0]){
                  finded=true;
                  break;
                }else{
                  if(datazh[i]!=dataen[i]){
                    same=false;
                  }
                }
                if(!same||finded){
                  break;
                }
              }
              if(finded){
                break;
              }
            }
            if(finded){
              cout<<GetName(openzh,false)<<" "<<countall++<<"  "<<UTF8ToGB(datazh.c_str()).c_str()<<endl;
              fpout<<datazh<<"\n";
            }else{
              cout<<GetName(openen,false)<<" "<<countall++<<"  "<<UTF8ToGB(dataen.c_str()).c_str()<<endl;
              fpout<<dataen<<"\n";
            }
            fpzh.close();
            fpzh.open(openzh.c_str(),ios::in);
          }
          fpzh.close();
          fpen.close();
          fpout.close();
          cout<<endl;
        }else{
          cout<<"開啟或創建"<<GetName(openout)<<"失敗\n(Open or created "<<GetName(openout)<<" fail)"<<endl;
        }
      }else{
        cout<<GetName(openen)<<"開啟失敗\n(Open "<<GetName(openen)<<" fail)"<<endl;
      }
    }else{
      cout<<GetName(openzh)<<"開啟失敗\n(Open "<<GetName(openzh)<<" fail)"<<endl;
    }
    system("pause");
    return 0;
}
