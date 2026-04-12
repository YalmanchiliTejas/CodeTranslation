#include<iostream>  
#include <cstdio>  
#include <iostream>  
#include <cstring>  
#include <string>  
#include <cmath>  
#include <queue>  
#include <set>  
#include <map>  
#include <complex>  
#include <algorithm>  
#include <vector>  
using namespace std;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define rep(i,l,r) for(int i=l;i<r;i++)
#define de(x) cout<<#x<<" = "<<x<<endl;
#define dd(x) cout<<#x<<" = "<<x<<",";
int main()
{
	char s[10];
	cin>>s;
	rep(i,0,strlen(s) - 1){
		if(s[i] == 'A' && s[i + 1] == 'C'){
			printf("Yes\n");
			return 0;
		}
	}
	printf("No\n");
	return 0;
}