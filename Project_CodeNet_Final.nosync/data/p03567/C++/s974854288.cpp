#include <bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) (x).begin(),(x).end()
#define LL long long
#define pii pair<int,int>
#define pll pair<LL,LL>

using namespace std;

int main(){

    string s;cin>>s;

    REP(i,s.size()-1)if(s[i]=='A'&&s[i+1]=='C'){
            cout<<"Yes"<<endl;
            return 0;
        }
    cout<<"No"<<endl;

    return 0;
}