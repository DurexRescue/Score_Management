#include "pch.h"
#include <iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<cmath>
#include<math.h>
using namespace std;
class student {
	string ID[50];
	string Name[50]; 
	string Source;
	float Math[50];
	float Physics[50]; 
	float English[50]; 
	float TotalScore[50];
	int ActualNumber=0;
	int currentpoint;
	float Math_Average = 0;
	float Physics_Average = 0;
	float English_Average = 0;
	float Total_Average = 0;
	float Math_SD = 0;
	float Physics_SD = 0;
	float English_SD = 0;
	int Ambiguous_Search[50] = {0};//记录原数组中下标位置
	int Ambiguous_Number = 0;//记录模糊查找到的要删除的元素的个数
public:
	void Menu();
	void Read();
	void Show();
	void Add();
	void Delete();
	void Modify();
	void SearchDirection();
	void SearchName_Direction();
	void SearchID_Direction();
	void SearchName_Explicit();
	void SearchID_Explicit();
	void SearchName_Ambiguous();
	void SearchID_Ambiguous();
	void Analyze();
	void Sort();
	void SaveDirection();
	void DirectSave();
	void Another_File();
	float Average(float *);
	float Average(float*,float*,float*);
	void Sum();
	void ScoreRange();
	void DeleteSpecialNavigator();
	void DeleteSpecial();
	void Recovery();
};
void student::Menu() {
	
	cout << "     Function Menu   " << endl;
	cout << "---------------------" << endl;
	cout << "【1】读入成绩           |" << endl;
	cout << "【2】显示成绩           |" << endl;
	cout << "【3】增加记录           |" << endl;
	cout << "【4】删除一个学生的记录 |" << endl;
	cout << "【5】成绩修改           |" << endl;
	cout << "【6】查找               |" << endl;
	cout << "【7】统计分析           |" << endl;
	cout << "【8】成绩排序           |" << endl;
	cout << "【9】保存数据           |" << endl;
	cout << "【10】模糊查找后删除    |" << endl;
	cout << "【0】退出系统           |" << endl;
	cout << "---------------------" << endl;
}
void student::Read() {
	ActualNumber = 0;
	string source;
	cout << "请完整地输入成绩文件的存放地址:";
	cin >> source;
	Source = source;
	ifstream ifile;               
	ifile.open(source);     
	int i = ActualNumber;
	if (!ifile)
	{
		cout << "该文件不存在!请重新输入！" << endl;
		
	}
	else
	while (1) {
		
		ifile >> ID[i] >> Name[i] >> Math[i]>>Physics[i]>>English[i];                                
		if (ifile.eof() != 0) break;            
		i++;
		ActualNumber++;
		
	}
	ifile.close();
	cout <<"此数据表中共有"<< ActualNumber<<"个数据."<<endl;
}
//输入模块
void student::Show() {
	cout << "-------------------------------------" << endl;
	cout << setw(8) << "学号" << setw(13) << "姓名" << setw(5) << "数学" << setw(5) << "物理" << setw(5) << "英语" << endl;
	for (int i = 0; i <= ActualNumber-1; i++)
	{
		cout << setw(6) << ID[i] << setw(10) << Name[i] << setw(5) << Math[i] << setw(5) << Physics[i] << setw(5) << English[i] << endl;
	}
	cout << "-------------------------------------" << endl;
}
//展示模块
void student::Add() {
	int choice;
	do {
		cout << "请输入学生姓名:";
		cin >> Name[ActualNumber];
		cout << "请输入学生学号:";
		cin >> ID[ActualNumber];
		cout << "请输入学生数学成绩:";
		cin >> Math[ActualNumber];
		cout << "请输入学生物理成绩:";
		cin >> Physics[ActualNumber];
		cout << "请输入学生英语成绩:";
		cin >> English[ActualNumber];
		ActualNumber++;
		cout << "还需要再增加记录吗？"<<endl;
		cout << "【0】结束"<<endl<<"【1】继续"<<endl<<"请输入您的选择：";
		
		cin >> choice;
	} while (choice > 0);
}
//增加记录模块
void student::SearchDirection() 
{
	cout << "您要以哪个关键字开展查找" << endl;
	cout << "【1】以学号为关键字开展查找" << endl;
	cout << "【2】以姓名为关键字开展查找" << endl;
	cout << "【3】查找处于某分数段内的同学" << endl;
	cout << "您的选择是:";
	int choice;
	cin >> choice;
	switch (choice)
	{
		case 1:SearchID_Direction(); break;
		case 2:SearchName_Direction(); break;
		case 3:ScoreRange(); break;
		default:
			cout << "您的输入有误，请重新输入"<<endl;
			SearchDirection();
	}
	
}
//搜索导航模块
void student::Delete() {
	currentpoint = 99;
	cout << "请输入您要用哪个关键字删除：" << endl;
	cout << "【1】学号" << endl;
	cout << "【2】姓名" << endl;
	cout << "您的选择是：";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:SearchID_Explicit(); break;
	case 2:SearchName_Explicit(); break;
	default:
		cout << "您的输入有误，请重新输入,程序自动复位，请重新选择删除关键字" << endl;
		Delete();
	}
	//此处为查找模块，调用精确查找函数（学号或姓名）
	cout << "您确定要删除" << Name[currentpoint] << "同学的记录？" << endl;
	cout << "【0】不删除" << endl << "【1】删除" << endl << "请输入您的选择";
	int choice1;
	cin >> choice1;
	if (choice1 == 0) { cout << "删除操作被终止，记录保留"<<endl; }
	else if (choice1 == 1)
	{
		cout << Name[currentpoint] ;
		for (int i = currentpoint; i <= ActualNumber - 1; i++)
		{
			
			ID[i] = ID[i + 1];
			Name[i] = Name[i + 1];
			Math[i] = Math[i + 1];
			Physics[i] = Physics[i + 1];
			English[i] = English[i + 1];

		}//此处为删除操作本体
		ActualNumber--;
		cout << "的记录已经被删除！" << endl;
	}
	else {
		cout << "您的输入有误，删除操作被终止，请重新操作！" << endl;
		Delete();
	}
}
//删除模块（依赖两个精确搜索模块）
void student::Modify() {
	currentpoint = 99;
	cout << "请输入您要用哪个关键字修改：" << endl;
	cout << "【1】学号" << endl;
	cout << "【2】姓名" << endl;
	cout << "您的选择是：";
	int choice,choice1,newgrade;
	cin >> choice;
	switch (choice)
	{
	case 1:SearchID_Explicit(); break;
	case 2:SearchName_Explicit(); break;
	default:
		cout << "您的输入有误，请重新输入,程序自动复位，请重新选择修改关键字" << endl;
		Delete();
	}
	//此处为查找模块，调用精确查找函数（学号或姓名）
	cout << "您要更改" << Name[currentpoint] << "的_______成绩" << endl;
	cout << "【1】数学" << endl << "【2】物理" << endl << "【3】英语"<<endl;
	cout << "请输入您的选择:";
	cin >> choice1;
	switch (choice1)
	{
	    case 1:
	    {
	     cout << "请输入新的数学成绩：";
		 cin >> newgrade;
		 Math[currentpoint] = newgrade;
		 break;
	    }
	    case 2:
		{
			cout << "请输入新的物理成绩：";
			cin >> newgrade;
			Physics[currentpoint] = newgrade;
			break;
		}
	    case 3:
		{
			cout << "请输入新的英语成绩：";
			cin >> newgrade;
			English[currentpoint] = newgrade;
			break;
		}
	default:
	   {
		cout << "输入有误，请重新输入,程序自动复位，请重新选择修改关键字";
		Modify();
	   }
	}
	//此处为修改操作本体
}
//修改模块（依赖两个精确搜索模块）
void student::SearchName_Direction() {
	cout << "请选择搜索方式" << endl<<"【1】精确搜索" << endl<<"【2】模糊搜索"<< endl<<"请输入您的选择：";
	int choice;
	cin >> choice;
	switch (choice)
	{
	   case 1:
	   {SearchName_Explicit(); break; }//调用名字精确搜素函数
	   case 2:
	   {SearchName_Ambiguous(); break; }//调用名字模糊搜索函数
	   default:
	    {cout << "输入有误，程序自动退回名字搜索模块，请再次选择";SearchName_Direction();}

	}
	//调用真正起作用名字搜索的函数
	return;
}
//名字搜索导航模块
void student::SearchID_Direction() {
	cout << "请选择搜索方式" << endl << "【1】精确搜索" << endl << "【2】模糊搜索" << endl << "请输入您的选择：";
	int choice;
	cin >> choice;
	switch (choice)
	{
	    case 1:
		SearchID_Explicit(); 
		break; //调用名字精确搜素函数
	    case 2:
		SearchID_Ambiguous(); 
		break; //调用名字模糊搜索函数
	    default:
	    cout << "输入有误，程序自动退回学号搜索模块，请再次选择"; 
		SearchID_Direction(); 
	}
	//调用真正起作用学号搜索的函数
	return;
	return;
}
//学号搜索导航模块
void student::SearchName_Explicit() {
	string input;
	currentpoint = 999;
	cout << "请输入同学的名字：";
	cin >> input;
	for (int i = 0; i <= ActualNumber - 1; i++)
	{
		if (Name[i] == input) {
			currentpoint = i;
			cout << "找到了！" << endl;
			cout << Name[i]<<"学号为：" << ID[i]<<endl;
			cout << Name[i] << "数学成绩为：" << Math[i] << endl;
			cout << Name[i] << "物理成绩为：" << Physics[i] << endl;
			cout << Name[i] << "英语成绩为：" << English[i] << endl;
		}
	}
	if (currentpoint == 999){cout << "查无此人"<<endl;}
}
//精确名字搜索模块
void student::SearchID_Explicit() {
	string input;
	currentpoint = 999;
	cout << "请输入同学的学号：";
	cin >> input;
	for (int i = 0; i <= ActualNumber - 1; i++)
	{
		if (ID[i] == input) {
			currentpoint = i;
			cout << "找到了！" << endl;
			cout << Name[i] << "学号为：" << ID[i] << endl;
			cout << Name[i] << "数学成绩为：" << Math[i] << endl;
			cout << Name[i] << "物理成绩为：" << Physics[i] << endl;
			cout << Name[i] << "英语成绩为：" << English[i] << endl;
		}
	}
	if (currentpoint == 999) { cout << "查无此人"<<endl; }
}
//精确学号搜索模块
void student::SearchName_Ambiguous() {
	string str;
	cout << "请输入查找同学的姓名：";
	cin >> str;
	for (int i = 0; i <= ActualNumber - 1; i++) {
		if (Name[i].find(str) != string::npos) {
			cout << "找到了！" << endl;
			cout << Name[i] << "同学的学号为:" << ID[i] << ",数学成绩为" << Math[i] << ",物理成绩为" << Physics[i] << ",英语成绩为" << English[i]<<endl;
			Ambiguous_Number++;//正确模糊数个数
			Ambiguous_Search[Ambiguous_Number - 1] = i;//存放位置下标
		}
	}
}
//模糊名字搜索模块
void student::SearchID_Ambiguous() {
	string str;
	cout << "请输入查找同学的学号：";
	cin >> str;
	for (int i = 0; i <= ActualNumber - 1; i++) {
		if (ID[i].find(str) != string::npos) {
			cout << "找到了！" << endl;
			cout << Name[i] << "同学的学号为:" << ID[i] << ",数学成绩为" << Math[i] << ",物理成绩为" << Physics[i] << ",英语成绩为" << English[i]<<endl;
			Ambiguous_Number++;//正确模糊数个数
			Ambiguous_Search[Ambiguous_Number - 1] = i;//存放位置下标
		}
	}
}
//模糊学号搜索模块
float student::Average(float *i) {
	int count = 0;
	int sum = 0;
	float Average;
	while (++count <= ActualNumber) {
		sum += *i;
		i++;
	}
	 Average = sum / ActualNumber;
	 return Average;
}
//单科求平均模块（隶属于成绩分析模块）
float student::Average(float* i,float*j,float*k) {
	int count = 0;
	int sum1 = 0;
	int sum2 = 0; 
	int sum3 = 0;
	float Average;
	while (++count <= ActualNumber) {
		sum1 += *i;
		i++;
		sum2 += *j;
		j++;
		sum3 += *k;
		k++;
	}
	Average = (sum1 + sum2 + sum3) / ActualNumber;
	return Average;
}
//三科求平均模块（隶属于成绩分析模块）
void student::Analyze() 
{
	cout << "欢迎进入成绩分析模块"<<endl;
	cout << "--------------------------------" << endl;
	cout << "          平均成绩分析          " << endl;
	cout << "数学平均分为：" << Average(Math) << endl; Math_Average = Average(Math);
	cout << "物理平均分为：" << Average(Physics) << endl; Physics_Average = Average(Physics);
	cout << "英语平均分为：" << Average(English) << endl; English_Average = Average(English);
	cout << "三科总分的平均成绩为：" << Average(Math,Physics,English) << endl;
	cout << "--------------------------------" << endl;
	int i,opm=0;
	for (i = 1; i <= ActualNumber; i++) {
		opm += pow(Math[i-1] - Math_Average, 2);
	}
	Math_SD = sqrt(1./ActualNumber*opm);//数学标准差
	
	int j, opp=0;
	for (i = 1; i <= ActualNumber; i++) {
		opp += pow(Physics[i-1] - Physics_Average, 2);
	}
	Physics_SD = sqrt(1. / ActualNumber * opm);//物理标准差'
	int k, ope=0;
	for (i = 1; i <= ActualNumber; i++) {
		ope += pow(English[i-1] - English_Average, 2);
	}
	English_SD = sqrt(1. / ActualNumber * ope);//英语标准差
	cout << "--------------------------------" << endl;
	cout << "           标准差分析           " << endl;
	cout << "数学标准差为：" << Math_SD << endl;
	cout << "物理标准差为：" << Physics_SD << endl;
	cout << "英语标准差为：" << English_SD << endl;
	cout << "--------------------------------" << endl;
	int Math_Count=0, Physics_Count=0, English_Count=0;
	for (i = 1; i <= ActualNumber; i++) {
		if (Math[i - 1] >= 60)Math_Count++;
	}
	for (i = 1; i <= ActualNumber; i++) {
		if (Physics[i - 1] >= 60)Physics_Count++;
	}
	for (i = 1; i <= ActualNumber; i++) {
		if (English[i - 1] >= 60)English_Count++;
	}
	cout << "--------------------------------" << endl;
	cout << "           合格率分析           " << endl;
	cout << "数学合格率为：" << float(Math_Count)/ActualNumber << endl;
	cout << "物理合格率为：" << float(Physics_Count) / ActualNumber << endl;
	cout << "英语合格率为：" << float(English_Count) / ActualNumber << endl;
	cout << "--------------------------------" << endl;
}
//成绩分析模块
void student::Sort() {
	cout << "您已进入排序模块" << endl;
	cout << "此程序块将按照从高到底的顺序进行排序" << endl;
	cout << "若总分相同，则按数学排序；" << endl;
	cout << "若总分和数学相同，则按物理排序；" << endl;
	cout << "若总分和各科成绩都相同，则按学号排序" << endl;
	cout << "以下为排序结果：" << endl;
	Sum();
	for (int i = 0; i <= ActualNumber-1; i++) {
		for (int j = ActualNumber - 1; j >= i+1; j--) {
			if (TotalScore[j] >= TotalScore[j - 1] )
			{
				int Swap_Total, Swap_Math, Swap_English, Swap_Physics;
				string Swap_Name, Swap_ID;
				Swap_Total = TotalScore[j];
				TotalScore[j] = TotalScore[j - 1];
				TotalScore[j - 1] = Swap_Total;
				
				Swap_Math = Math[j];
				Math[j] = Math[j - 1];
				Math[j -1] = Swap_Math;

				Swap_Physics = Physics[j];
				Physics[j] = Physics[j - 1];
				Physics[j - 1] = Swap_Physics;

				Swap_English = English[j];
				English[j] = English[j - 1];
				English[j - 1] = Swap_English;

				Swap_Name = Name[j];
				Name[j] = Name[j - 1];
				Name[j - 1] = Swap_Name;

				Swap_ID = ID[j];
				ID[j] = ID[j - 1];
				ID[j - 1] = Swap_ID;
			}
		}
		
	}
	Show();
	//cout << "-------------------------------------" << endl;
}
//成绩排序模块
void student::SaveDirection() {
	cout << "请输入保存方式：" << endl;
	cout << "【1】原文件保存(请注意，这样做会覆盖原文件)" << endl << "【2】另存为..."<<endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:
	{DirectSave();
	break; }
	case 2:
	{Another_File();
	break; }
	default: {
		cout << "输入错误，请重新选择：";
		SaveDirection();
	}
	}
}
//文件输出导航模块
void student::Sum() {
	for (int i = 0; i <= ActualNumber - 1; i++) {
		TotalScore[i] = Math[i] + Physics[i] + English[i];
	}

}
//求总分模块（隶属于成绩排序模块)
void student::ScoreRange() {
	cout << "请输入要查找的科目:" << endl;
	cout << "【1】数学"<<endl;
	cout << "【2】物理"<<endl;
	cout << "【3】英语"<<endl;
	cout << "请输入您的选择：";
	int choice;
	int left = 0;
	int right = 0;
	cin >> choice;
	int count = 0;
	switch (choice)
	{
	case 1:
		cout << "请输入要查找分数段的左值：";
		cin >> left;
		cout << "请输入要查找分数段的右值：";
		cin >> right;
		
		for (int i = 0; i <= ActualNumber - 1; i++) {
			if (Math[i] >= left && Math[i] <= right) {
				count++;
			}
		}
		if (count == 0) { cout << "此分数段内没有内容!" << endl; break; }
		cout << setw(8) << "学号" << setw(13) << "姓名" << setw(5) << "数学" << setw(5) << "物理" << setw(5) << "英语" << endl;
		for (int i = 0; i <= ActualNumber - 1; i++) {
			if (Math[i] >= left && Math[i] <= right) {
				cout << setw(6) << ID[i] << setw(10) << Name[i] << setw(5) << Math[i] << setw(5) << Physics[i] << setw(5) << English[i] << endl;
			}
		}
		break;
	case 2:
		cout << "请输入要查找分数段的左值：";
		cin >> left;
		cout << "请输入要查找分数段的右值：";
		cin >> right;

		for (int i = 0; i <= ActualNumber - 1; i++) {
			if (Physics[i] >= left && Physics[i] <= right) {
				count++;
			}
		}
		if (count == 0) { cout << "此分数段内没有内容!" << endl; break; }
		cout << setw(8) << "学号" << setw(13) << "姓名" << setw(5) << "数学" << setw(5) << "物理" << setw(5) << "英语" << endl;
		for (int i = 0; i <= ActualNumber - 1; i++) {
			if (Physics[i] >= left && Physics[i] <= right) {
				cout << setw(6) << ID[i] << setw(10) << Name[i] << setw(5) << Physics[i] << setw(5) << Physics[i] << setw(5) << English[i] << endl;
			}
		}
		break;
	case 3:
		cout << "请输入要查找分数段的左值：";
		cin >> left;
		cout << "请输入要查找分数段的右值：";
		cin >> right;

		for (int i = 0; i <= ActualNumber - 1; i++) {
			if (English[i] >= left && English[i] <= right) {
				count++;
			}
		}
		if (count == 0) { cout << "此分数段内没有内容!" << endl; break; }
		cout << setw(8) << "学号" << setw(13) << "姓名" << setw(5) << "数学" << setw(5) << "物理" << setw(5) << "英语" << endl;
		for (int i = 0; i <= ActualNumber - 1; i++) {
			if (English[i] >= left && English[i] <= right) {
				cout << setw(6) << ID[i] << setw(10) << Name[i] << setw(5) << English[i] << setw(5) << Physics[i] << setw(5) << English[i] << endl;
			}
		}
		break;
	default:
		cout<<"您的输入有误，请重新输入";
		ScoreRange();
	}


}
//分数段查找模块
void student::DirectSave(){
	ofstream ofile;               //定义输出文件
	ofile.open("Source"); //作为输出文件打开
	for (int i = 0; i <= ActualNumber - 1; i++)
		ofile << setw(6) << ID[i] << setw(10) << Name[i] << setw(5) << Math[i] << setw(5) << Physics[i] << setw(5) << English[i] << endl;
	ofile.close();
}
//原文件保存实现模块
void student::Another_File(){
	ofstream ofile;               //定义输出文件
	cout << "请输入保存地址:";
	string source;
	cin >> source;
	ofile.open(source); //作为输出文件打开
	for (int i = 0; i <= ActualNumber - 1; i++)
		ofile << setw(6) << ID[i] << setw(10) << Name[i] << setw(5) << Math[i] << setw(5) << Physics[i] << setw(5) << English[i] << endl;
	ofile.close();
}
//另存为保存实现模块
void student::DeleteSpecialNavigator(){
	cout << "欢迎进入模糊删除模块，请问您需要:" << endl << "【1】删除数据" << endl << "【2】恢复数据"<<endl;
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:DeleteSpecial(); break;
	case 2:Recovery(); break;
	default:
		cout << "您的输入有误，请重新输入" << endl ;
		DeleteSpecialNavigator();
		break;
	}

}
//模糊删除导航模块
void  student::DeleteSpecial() {
	Ambiguous_Search[50] = { 0 };
	Ambiguous_Number = 0;//预留初始化空间
	cout << "请输入您要用哪个关键字删除：" << endl;
	cout << "【1】学号" << endl;
	cout << "【2】姓名" << endl;
	cout << "您的选择是：";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case 1:SearchID_Ambiguous(); break;
	case 2:SearchName_Ambiguous(); break;
	default:
		cout << "您的输入有误，请重新输入,程序自动复位，请重新选择删除关键字" << endl;
		DeleteSpecial();
	}
	//此处为查找模块，调用模糊查找函数（学号或姓名）
	cout << "您确定要删除" << "以下" << "同学的记录？" << endl;
	cout << "-------------------------------------" << endl;
	cout << setw(8) << "学号" << setw(13) << "姓名" << setw(5) << "数学" << setw(5) << "物理" << setw(5) << "英语" << endl;
	for (int i = 0; i <= Ambiguous_Number - 1; i++)
	{
		cout << setw(6) << ID[Ambiguous_Search[i]] << setw(10) << Name[Ambiguous_Search[i]] << setw(5) << Math[Ambiguous_Search[i]] << setw(5) << Physics[Ambiguous_Search[i]] << setw(5) << English[Ambiguous_Search[i]] << endl;
	}
	cout << "-------------------------------------" << endl;

	cout << "【0】不删除" << endl << "【1】删除" << endl << "请输入您的选择"<<endl;
	int choice1;
	cin >> choice1;
	if (choice1 == 0) { cout << "删除操作被终止，记录保留" << endl; }
	else if (choice1 == 1)
	{
		ofstream ofile;               //定义输出文件
		ofile.open("c:\\recycle.txt"); //作为输出文件打开
		for (int i = 0; i <= Ambiguous_Number - 1; i++)
			ofile << setw(6) << ID[Ambiguous_Search[i]] << setw(10) << Name[Ambiguous_Search[i]] << setw(5) << Math[Ambiguous_Search[i]] << setw(5) << Physics[Ambiguous_Search[i]] << setw(5) << English[Ambiguous_Search[i]] << endl;
		ofile.close();
		for (int i = 0; i <= Ambiguous_Number - 1; i++)
		{

			ID[Ambiguous_Search[i]] = ID[Ambiguous_Search[i] + 1];
			Name[Ambiguous_Search[i]] = Name[Ambiguous_Search[i] + 1];
			Math[Ambiguous_Search[i]] = Math[Ambiguous_Search[i] + 1];
			Physics[Ambiguous_Search[i]] = Physics[Ambiguous_Search[i] + 1];
			English[Ambiguous_Search[i]] = English[Ambiguous_Search[i] + 1];
			ActualNumber--;

		}//此处为删除操作本体
		cout << "所选已经被删除！" << endl;
		cout << "表内目前还有"<<ActualNumber<<"组数据。";
	}
	else {
		cout << "您的输入有误，删除操作被终止，请重新操作！" << endl;
		Delete();
	}




}
//模糊删除实现模块
void student::Recovery() {
	cout << "数据恢复中..."<<endl;
	ifstream ifile;
	
	ifile.open("c:\\recycle.txt");
	int i = ActualNumber;
	while (1) {

		ifile >> ID[i] >> Name[i] >> Math[i] >> Physics[i] >> English[i];
		if (ifile.eof() != 0) break;
		i++;
		ActualNumber++;

	}
	ifile.close();
	ofstream myfile("c:\\recycle.txt", ios::trunc);
	myfile.close();
	cout << "恢复成功！" << endl;
	cout << "目前有" << ActualNumber << "个数据！" << endl;
}
//模糊删除恢复实现模块

int main() {
	student s;
	cout << "欢迎进入学生成绩管理系统" << endl;
	s.Menu();
	int a=999;
	while (a!=0)
	{
		cout << "请输入您的选择：";
		cin >> a;
		cout << "您的选择是" << a << ".";
		switch (a)
		{
		case 1: {
			cout << "读入成绩" << endl;
			s.Read();
			cout << "读入成绩执行完毕，请进行其他操作" << endl;
			cout << "--------------------------------" << endl;
			s.Menu();
			break;
		}
		case 2: {
			cout << "显示成绩" << endl;
			s.Show();
			cout << "显示成绩执行完毕，请进行其他操作" << endl;
			cout << "--------------------------------" << endl;
			s.Menu();
			break;
		}
		case 3: {
			cout << "增加记录" << endl;
			s.Add();
			cout << "增加记录执行完毕，请进行其他操作" << endl;
			cout << "--------------------------------" << endl;
			s.Menu();
			break;
		}
		case 4: {
			cout << "删除一个学生的记录" << endl;
			s.Delete();
			cout << "已经从删除模块中跳出，请进行其他操作" << endl;
			cout << "------------------------------------" << endl;
			s.Menu();
			break;
		}
		case 5: {
			cout << "成绩修改" << endl;
			s.Modify();
			cout << "成绩修改执行完毕，请进行其他操作" << endl;
			cout << "--------------------------------" << endl;
			s.Menu();
			break;
		}
		case 6: {
			cout << "查找" << endl;
			s.SearchDirection();
			cout << "查找执行完毕，请进行其他操作" << endl;
			cout << "----------------------------" << endl;
			s.Menu();
			break;
		}
		case 7: {
			cout << "统计分析" << endl;
			s.Analyze();
			cout << "统计分析执行完毕，请进行其他操作" << endl;
			cout << "--------------------------------" << endl;
			s.Menu();
			break;
		}
		case 8: {
			cout << "成绩排序" << endl;
			s.Sort();
			cout << "成绩排序执行完毕，请进行其他操作" << endl;
			cout << "--------------------------------" << endl;
			s.Menu();
			break;
		}
		case 9: {
			cout << "保存数据" << endl;
			s.SaveDirection();
			cout << "保存数据执行完毕，请进行其他操作" << endl;
			cout << "--------------------------------" << endl;
			s.Menu();
			break;
		}
		case 0: {
			cout << "退出系统" << endl;
			cout << "退出系统成功，欢迎再次使用。" << endl;
			cout << "----------------------------" << endl;
			break;
		}
		case 10: {
			cout << "模糊查找删除" << endl;
			s.DeleteSpecialNavigator();
			cout << "已经退出模糊删除模块，请进行其他操作 " << endl;
			cout << "-------------------------------------" << endl;
			s. Menu();
			break;
		}
		default:
			cout << "您的输入有误，请重新输入：" << endl;
			s.Menu();
			break;
		}
	}
	//总导航模块
}