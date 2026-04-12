#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
 
using namespace std;
 
#define PB push_back
#define MP make_pairA
#define REP(i,n) for(int i=0;i<(n);i++)
int main()
{
    string s;
    bool f=false;
    cin>>s;
    REP(i,s.size()-1){
        if(s[i]=='A'&&s[i+1]=='C')f=true;
    }
    if(f)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
