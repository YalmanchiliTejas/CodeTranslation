#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
int main()
{
    string s;
    cin >> s;
    
    string out="No";
    REP(i, s.size()-1){
        if(s[i]=='A' && s[i+1]=='C') out = "Yes";
    }
    cout << out<< endl; 

   return 0;
}