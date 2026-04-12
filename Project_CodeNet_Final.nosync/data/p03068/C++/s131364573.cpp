#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include <vector>
#include <string.h>
#include <string>

using namespace std;
#define  rep(i,n) for(int i=0;i<n;i++)
#define  rrep(i,n) for(int i=n;i>0;i--)
#define  REP(i,a,b) for(int i=a;i<b;i++)
typedef long long int lld;
typedef vector<lld> vl;
typedef vector<int> vi;
typedef vector<string> vs;


//int arr[N]
////sort(arr,arr +N)
//vector <int> hoge
////sort(hoge.begin(),hoge.end());
///min_element(hoge.begin(),hoge.end();　最小値　　　最大値はmax_element();


int map[100][100];
vi cl(1000);
vi ol(1000);


void print(int n);
void next(int locate);

int main() {
	int k,n;
	string s,tmp;
	 cin>>n>>s>>k;
	 string a;
	 a=s[k-1];
	 rep(i,n){
	 	tmp=s[i];
	 	if(tmp!=a){
	 		cout<<"*";
	 	}
	 	else
	 		cout<<s[i];
	 }
	 return 0;
}