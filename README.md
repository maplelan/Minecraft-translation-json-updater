# Minecraft-translation-json-updater Minecraft模組翻譯文件更新器
updata Minecraft mod translation json 更新Minecraft模組翻譯文件

EX:

1.輸入舊版文件:

{

	"_": "->------------------------]  Game Elements  [------------------------<-",

	"block.create.acacia_window": "相思木窗戶",
	"block.create.acacia_window_pane": "相思木窗戶板",
	"block.create.adjustable_chain_gearshift": "可調式連動齒輪箱",
	"block.create.adjustable_pulse": "可調式脈沖中繼器",
	"block.create.adjustable_crate": "可調式板條箱",
	
	"_": "謝謝您翻譯Creat!"

}

2.輸入新版文件:

{

	"_": "->------------------------]  Game Elements  [------------------------<-",

	"block.create.acacia_window": "Acacia Window",
	"block.create.acacia_window_pane": "Acacia Window Pane",
	"block.create.adjustable_chain_gearshift": "Adjustable Chain Gearshift",
	"block.create.adjustable_crate": "Adjustable Crate",
	"block.create.adjustable_pulse_repeater": "Adjustable Pulse Repeater",

	"_": "Thank you for translating Create!"

}

3.輸出:

{

	"_": "->------------------------]  Game Elements  [------------------------<-",

	"block.create.acacia_window": "相思木窗戶",
	"block.create.acacia_window_pane": "相思木窗戶板",
	"block.create.adjustable_chain_gearshift": "可調式連動齒輪箱",
	"block.create.adjustable_crate": "可調式板條箱",
	"block.create.adjustable_pulse_repeater": "Adjustable Pulse Repeater",

	"_": "->------------------------]  Game Elements  [------------------------<-",

}

注意:

1.由於目前只是簡單使用 所有相同開頭的將被替換成第一個找到的 像是Game Elements那行 但不影響Minecraft讀取 未來再修改

2.目前僅測試過繁中翻譯檔案 其他語言會不會出事我不知道

3.我第一次使用Github管理 可能做的不是很好
