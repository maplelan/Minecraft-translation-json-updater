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
//UTF8ToGB(��X.c_str()).c_str()
string UTF8ToGB(const char* str)
{
	string result;
	WCHAR *strSrc;
	LPSTR szRes;

	//��o�{���ܼƪ��j�p
	int i = MultiByteToWideChar(CP_UTF8, 0, str, -1, NULL, 0);
	strSrc = new WCHAR[i + 1];
	MultiByteToWideChar(CP_UTF8, 0, str, -1, strSrc, i);

	//��o�{���ܼƪ��j�p
	i = WideCharToMultiByte(CP_ACP, 0, strSrc, -1, NULL, 0, NULL, NULL);
	szRes = new CHAR[i + 1];
	WideCharToMultiByte(CP_ACP, 0, strSrc, -1, szRes, i, NULL, NULL);

	result = szRes;
	delete[]strSrc;
	delete[]szRes;

	return result;
}
//---------------------------------------------------------------------------
//GetName(�ɮ׸��|,�O�_�t�����ɦW(�w�]��))
string GetName(string filepath,bool Extension=true){
  string filename=filepath;
  const size_t last_slash_idx = filename.find_last_of("\\/");
  if (std::string::npos != last_slash_idx)
  {
      filename.erase(0, last_slash_idx + 1);
  }
  // �������ɦW
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
    cout<<"�N�ª����즲�i�����Ϊ�����J�ɮ׸��|�ë��UEnter:\n(Drag the old version file into the window or enter the file path and press Enter.):"<<endl;
    string openzh="";
    getline(cin,openzh);
    openzh.erase(std::remove(openzh.begin(), openzh.end(), '"'), openzh.end());
    fstream fpzh;
    fpzh.open(openzh.c_str(),ios::in);
    if(fpzh){
      cout<<"���\\�}��"<<GetName(openzh)<<"\n(Open "<<GetName(openzh)<<" success)"<<endl<<endl;
      cout<<"�N�s�����즲�i�����Ϊ�����J�ɮ׸��|�ë��UEnter:\n(Drag the new version file into the window or enter the file path and press Enter.):"<<endl;
      string openen="";
      getline(cin,openen);
      openen.erase(std::remove(openen.begin(), openen.end(), '"'), openen.end());
      fstream fpen;
      fpen.open(openen.c_str(),ios::in);
      if(fpen){
        cout<<"���\\�}��"<<GetName(openen)<<"\n(Open "<<GetName(openen)<<" success)"<<endl<<endl;
        cout<<"�N�̲׿�X���즲�i�����Ϊ�����J�ɮ׸��|�ë��UEnter �p�G��󤤦����e�N�|�Q�л\\ �p�G�L���|�ۦ�إ�:\n(Drag the output file into the window or enter the file path and press Enter. If there is content in the file, it will be overwritten. If there is no file, it will be created.):"<<endl;
        string openout="";
        getline(cin,openout);
        openout.erase(std::remove(openout.begin(), openout.end(), '"'), openout.end());
        fstream fpout;
        fpout.open(openout.c_str(),ios::out|ios::trunc);
        if(fpout){
          cout<<"�}�ҩΫإ�"<<GetName(openout)<<"���\\\n(Open or created "<<GetName(openout)<<" success)"<<endl<<endl;
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
          cout<<"�}�ҩγЫ�"<<GetName(openout)<<"����\n(Open or created "<<GetName(openout)<<" fail)"<<endl;
        }
      }else{
        cout<<GetName(openen)<<"�}�ҥ���\n(Open "<<GetName(openen)<<" fail)"<<endl;
      }
    }else{
      cout<<GetName(openzh)<<"�}�ҥ���\n(Open "<<GetName(openzh)<<" fail)"<<endl;
    }
    system("pause");
    return 0;
}
