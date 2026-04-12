#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned LL
#define PII pair<int,int>
#define VI vector<int>
#define VPII vector< PII >
#define VVI vector< VI >
#define PB push_back
#define F first
#define S second
const int INF=1e9;
const int MOD=1e9+7;
string s;
int main(){
    cin>>s;
    for(int i=0;i<s.size()-1;i++){
        if(s[i]=='A'&&s[i+1]=='C')return 0*puts("Yes");
    }
    puts("No");
    return 0;
}