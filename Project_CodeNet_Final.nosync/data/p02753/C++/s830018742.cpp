#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    string s;
    cin>>s;
    int a=0,b=0;
    for(int i=0;i<int(s.size());i++){
        if(s[i]=='A')
        a++;
        else
        b++;
    }
    if(a>0 & b>0)
    cout<<"Yes"<<endl;
    else
    cout<<"No"<<endl;
}