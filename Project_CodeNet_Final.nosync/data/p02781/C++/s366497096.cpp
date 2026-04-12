// I want to AC


#include <vector>
#include<stdio.h>
#include<string.h>
#include <cstring>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <set>
#include<cstring>
#include<queue>
#include<assert.h>
#define ll long long
#define MODD 1000000007
#define  pii  pair<int,int>
#include<stdio.h>
#include<string.h>
#include<bits/stdc++.h>
//#define  ll long long
using namespace std;
const int maxn = 1e6+7;
#define FOR(i, x, y) for (ll i = (x), _##i = (y); i < _##i; ++i)


string s;
int  k ;
ll dp[maxn];
int main() {
	 cin >>s;
	 int len = s.size();
	cin >>k;
	if(k==1) cout<<(len-1)*9+s[0]-'0';
	else if(k==2){
		if(len <2)cout<<0;
		else {
			int kk =0 ;int pos =0 ;
			for(int i=1;i<len;i++){
				if(s[i]!='0') {
					pos = i; break;
				}
			}
			if(pos ==0 )cout<<(len-1)*(len-2)*81/2+(s[0]-'0'-1)*9*(len-1);
			else 
			cout<<(len-1)*(len-2)*81/2+(s[0]-'0'-1)*9*(len-1)+(len-pos-1)*9+s[pos]-'0';
			//else 
		}
	}
	else {
		if(len <3)cout<<0;
			else{
				int pos =0 ;int kk=0 ;int pp =0;int f=0;
				for(int i=1;i<len;i++) {
					if(s[i]!='0'){
						if(!f)pos = i ;
						else pp= i;
						f ++;
					}
					if(f==2)break;
				}//(len - pos)*(len-1-pos)*81/2+(s[pos]-'0'-1)*9*(len-pos)+(len-pp-1)*9+s[pp]-'0';
				int llen = (len-pos-2)*(len-pos-1)*81/2+(s[pos]-'0'-1)*9*(len-pos-1)+(len-pp-1 )*9+s[pp]-'0';
				if(pos ==0)llen =0 ;
				else if(pp ==0 )llen = (len-pos-2)*(len-pos-1)*81/2+(s[pos]-'0'-1)*9*(len-pos-1);
				 cout<<(len-3)*(len-1)*(len-2)*81/6*9+(s[0]-'0'-1)*81*(len-1)*(len-2)/2+llen;
			} 
			 
	}
	return 0;



}