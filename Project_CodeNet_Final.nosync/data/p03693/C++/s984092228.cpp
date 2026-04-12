#include <iostream>
#include <random>
#include <fstream> //iostreamのファイル入出力をサポート
#include <vector>
#include <algorithm>
#include <string>
#include <math.h> 
#include <time.h>
#define FOR(i,k,n) for((i)=(k);(i)<(n);(i)++)
#define rep(i,n) for (int i=0;i<(n);i++)
#define REP(i,n) for (int i=0;i<(n);i++)
#define pb push_back
#define all(a) (a).begin(),(a).end()  //greater<int>()
#define ll long long
#define PII pair<int,int>
#define pii pair<int,int>
#define pcc pair<char,char>
#define pic pair<int,char>
#define pci pair<char,int>
#define VS vector<string>
#define vs vector<string>
#define VI vector<int>
#define vi vector<int>
using namespace std;

int main(){
	int r,g,b;
	cin>>r>>g>>b;

	int a = 10*g+b;
	if(a%4==0){
		cout<<"YES"<<endl;
		return 0;
	}

	cout<<"NO"<<endl;
	return 0;
}