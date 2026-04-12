#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define p_q priority_queue
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)



int main(){
    string s;
    cin>>s;
    
    if(s.at(0)==s.at(1)&&s.at(1)==s.at(2)){
        cout<<"No"<<endl;
    }else{
        cout<<"Yes"<<endl;
    }
}