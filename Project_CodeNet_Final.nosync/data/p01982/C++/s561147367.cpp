//#include <bits/stdc++.h>
//#include <stdio.h>
#include<iostream>
#include<cstdio>
#include<bitset>
#include<algorithm>
#include<vector>
#include<list>
#include<queue>
#include<stack>
#include<string>
#include<string.h>
#include<cmath>
#include<utility>
#include<functional>
#include<map>
#include<set>
#include<cctype>
#include<fstream>
 
 
#define FOR(i, a, b) for( int i=(a);i<=(b);i++)
#define RFOR(i, a, b) for( int i=(a);i>=(b);i--)
#define LFOR(i, a, b) for( long long int i=(a);i<=(b);i++)
#define LRFOR(i, a, b) for(long long int i=(a);i>=(b);i--)
#define MOD 1000000007
#define INF 1000000000 //2000000000
#define LINF 1000000000000000000 //9000000000000000000
#define PI 3.14159265358979
#define MAXI 7500000
 
using namespace std;
typedef long long int ll;
typedef pair< long long int, long long  int> P;
 
int dy[5] = { 0,0,1,-1,0 };
int dx[5] = { 1,-1,0,0,0 };
 
int main(void){

	while(1){
		int n,l,r;
		int count=0;
		int a[4001];
		bool flag=false;

		cin>>n>>l>>r;
		if(n==0){
			break;
		}
		FOR(i,1,n){
			cin>>a[i];
		}

		FOR(i,l,r){
			flag=false;

			FOR(j,1,n){
				if(i%a[j]==0){
					if(j%2==1){
						flag=true;
						count++;
					}else{
						flag=true;
					}
					break;
				}
			}
			if(flag==false){
				if(n%2==0){
					count++;
				}
			}
		}

		cout<<count<<endl;
		
	}

}
