#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <algorithm>
#include <functional>
#define inf 0x7fffffff
using namespace std;
typedef long long ll;
const int MAXN=1e5+10;
const int MAX=1e5+10;
const double eps=1e-6;



int main(){
    #ifdef ONLINE_JUDGE
    #else
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    #endif
 	
    string s;
    int juge=0;
    cin>>s;
    for(int i=0;i<s.size();i++){
    	if(s[i]=='A'){
    		if(i+1<s.size()&&s[i+1]=='C')
    			juge=1;
    	}
    }
    if(juge)
    	cout<<"Yes"<<endl;
    else
    	cout<<"No"<<endl;

    return 0;	
}