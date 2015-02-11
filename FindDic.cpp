/*
author:Zhou Wei
Contract Email:nkzhouwei@foxmail.com
Version:V1.0
Date:2015/02/11
Usage: convert the number in keyboard into the word in dictionary.

*/

#include <iostream>
#include<list>
#include <hash_map>
#include<set>
#include<string>
#include<vector>
#include <stdlib.h>
using namespace std;


vector<string> JiuGongInput(string InputString){

//TO-DO:��Ҫ��dicMap ��ϣ�����������ñ����ļ�����hash_map
/*��dicMap �洢�����ַ��͵��ʵ�ƥ���ϵ��һ���ַ������ж������ƥ�䣬��vector�洢ƥ�䵥�ʣ���string�洢�����ַ�
������ʾ�������ַ������յ��ʵ�ƥ���
��������->�ַ�->����
2->a->ago;able
22->ab->able,abort
22->ac->accomplish
27->at->atul
����������Ͼ����������

*/
		hash_map<string, vector<string>> dicMap;
		vector<string> wordList;
		wordList.push_back("ago");
		wordList.push_back("able");
		dicMap["a"]=wordList;
		vector<string> wordList2;
		wordList2.push_back("able");
		wordList2.push_back("abort");
		dicMap["ab"]= wordList2;
		vector<string> wordList3;
		wordList3.push_back("accomplish");
		dicMap["ac"]= wordList3;
		vector<string> wordList4;
		wordList4.push_back("atul");
		dicMap["at"]= wordList4;

		
//hmap�����洢�������ּ�������ĸ��ƥ������ַ�2����	"abc" �Դ�����
		hash_map<int, string> hmap;
		hmap[2]= "abc";
		hmap[3]="def";
		hmap[4]="ghi";
		hmap[5]="jkl";
		hmap[6]="mno";
		hmap[7]="pqrs";
		hmap[8]="tuv";
		hmap[9]="wxyz";
//result vector������������ĵ���
		cout<<"\tInput digitals in keyboard:"<<InputString<<endl;
		int length=InputString.length();
		vector <string> result;
	
		
		for (int i = 0; i < length;i++)
		{
			char c=InputString[i];

 //�����쳣���벢ֱ�ӷ���
			if (c>'9' || c<='1')
			{
			cout<<"\t\tinvalid input"<<endl;
			return result;
			}
			int j = c -'0';
			
			string s=hmap[j];

//��result�ĳ���Ϊ0ʱ�������е��������֣�ת��Ϊ�����ϵ���ĸ������ĸ��dicMapʱ��������ĸ����result vector		
			if(result.size()==0){
				for(int n=0;n<s.length();n++){
					char tmp[1];
					tmp[0]=s[n];
					string sNews(tmp,1);
					hash_map<string, vector<string>> ::iterator hi = dicMap.find(sNews);
					if(hi !=dicMap.end())
						result.push_back(sNews);
									
				}
			}
//��result size��Ϊ0��������ӵ����ּ��̶�Ӧ����ĸ����result�
			else{
				int resultSize=result.size();
				for(int w=0;w<resultSize;w++){
					string old=result.front();
					result.erase(result.begin());
					for(int n=0;n<s.length();n++){
				
					char tmp[1];
					tmp[0]=s[n];

					string sNews2(tmp,1);
					
					hash_map<string, vector<string>> ::iterator hi = dicMap.find(old+sNews2);
					if(hi !=dicMap.end())
						result.push_back(old+sNews2);
													
					}
				}
			}
						
			
		}
//��������dicMap�м�����ĸ��Ӧ�ĵ��ʼ���result��		
		int Fsize=result.size();
		for(int k =0; k<Fsize;k++)
		{
			string key=result[k];
			vector <string> list2=dicMap[key];
			for(int i=0;i<list2.size();i++){
				result.push_back(list2[i]);
				
			}
		}

//���result���
	vector<string>::iterator it=result.begin();
	for (it=result.begin();it!=result.end();it++) 
        cout<<"\t\t"<<*it<<'\n';		
    
	if (result.size()==0)
		cout<<"\t\tno match word in dic!"<<endl;

	return result;
	

}



void main()
{
	//test cases
	cout<<"test1: for invalid input:"<<endl;
	JiuGongInput("1");
	JiuGongInput("M");
	JiuGongInput("21");
	JiuGongInput("0");
	JiuGongInput("2*#");

	cout<<"test2:for single character in the dictionary:"<<endl;
	JiuGongInput("2");

	cout<<"test3:for two characters in the dictionary:"<<endl;
	JiuGongInput("22");
	JiuGongInput("27");


	cout<<"test4:for two/ three characters not the dictionary:"<<endl;
	JiuGongInput("223");
	JiuGongInput("23");

	cout<<"test5: long characters not the dictionary:"<<endl;
	JiuGongInput("234567823456789");


}
