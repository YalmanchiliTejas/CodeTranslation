#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<cmath>
#include<queue>
#include<stack>
#include<list>

using namespace std;
using ll = long long;

int main(){
    string s;
    cin>>s;
    bool ok=false;
    if(s[0] != s[1]) ok=true;
    else if(s[1] != s[2]) ok=true;

    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}