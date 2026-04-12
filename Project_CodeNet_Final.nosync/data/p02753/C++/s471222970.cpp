#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<math.h>
#include<map>
#include<unordered_map> 
#include<vector>
#include<queue>
#include<set>
//#include<bits/stdc++.h>
#include<deque> 
#include<bitset>
#include<string>
#define N 40
#define K 300005
#define MOD 1e9+7
#define int long long 
#define fastio  ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
using namespace std;
//these are prefic kind of stuff..




int32_t main(){
	string s;
	cin>>s;
	int a = 0,b = 0;
	for(int i=0;i<s.length();i++){
		if(s[i] == 'A')
			a++;
		else
			b++;
	}
	if(a >0 && b >0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
		
	
	
	
	
	
	
			
}
