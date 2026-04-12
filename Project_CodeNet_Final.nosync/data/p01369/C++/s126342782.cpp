#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
#include<ctime>
#include<cstring>
#include<iomanip>

#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define dump(a) (cerr << #a << "=" << (a) << endl)
#define DUMP(list) cout << "{"; for(auto nth : list){ cout << nth << " ";}cout << "}" << endl;

using namespace std;

string table[]={"qwertasdfgzxcvb","yuiophjklnm"};


int main(){
	
	while(true){
		string str;
		cin >> str;

		if(str=="#") break;
		
		int count=0;
		
		int flag = -1;
		bool s_flag = false;
		//右手==0,左手==1
		for(int i=0;i<str.length();i++){
			for(int k=0;k<table[0].length();k++){
				if(str[i]==table[0][k] && (flag==0 || flag==-1)){
					if(i==0){
						flag=1;
						break;
					}
					s_flag=true;
					count++;
					flag=1;
					break;
				}
				if(str[i]==table[1][k] && (flag==1 || flag==-1)){
					if(i==0){ 
						flag=0;
						break;
					}
					count++;
					flag=0;
					break;	
				}
			}
		}
	
		cout << count << endl;
	}

}