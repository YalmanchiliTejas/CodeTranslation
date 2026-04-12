#include <cstdio>
#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
#include <cmath>
#include <iomanip>
#include <regex>
#include <queue>
using namespace std;
using ll = long long;
using Lf = long double;
using plong = pair<ll,ll>;
const int mod = 1000000007;
 
vector<bool> res;
string S;
ll N;
bool ok(bool fir,bool sec,vector<bool> res){
    bool flag = true;
    if(res[1]&&fir){
        if(res[0]!=res[2])flag = false;
    }else if(!res[1]&&fir){
        if(res[0]==res[2])flag = false;
        
    }else if(res[1]&&!fir){
        if(res[0]==res[2])flag = false;
        
    }else{
        if(res[0]!=res[2])flag = false;
        
    }

    if(res[2]&&sec){
        if(res[1]!=res[3])flag = false;
    }else if(!res[2]&&sec){
        if(res[1]==res[3])flag = false;
    }else if(res[2]&&!sec){
        if(res[1]==res[3])flag = false;
    }else{
        if(res[1]!=res[3])flag = false;
    }
    return flag;

}

bool sw(bool fir,bool sec){
    res[0] = fir;
    res[1] = sec;
    for(ll i=1;i<N-1;i++){
        if(res[i]){
            if(S[i]=='o'){
                res[i+1]=res[i-1];
            }else{
                res[i+1]=!res[i-1];
            }
        }else{
            if(S[i]=='o'){
                res[i+1]=!res[i-1];
            }else{
                res[i+1]=res[i-1];
            }
        }
    }
    vector<bool> tmp;
    tmp.push_back(res[N-2]);
    tmp.push_back(res[N-1]);
    tmp.push_back(res[0]);
    tmp.push_back(res[1]);
    return ok(S[N-1]=='o',S[0]=='o',tmp);

}

int main(){
 
    cin>>N>>S;
    res.resize(N); //true:Sheep, false: Wolfe
    if(sw(true,true))goto END;
    if(sw(true,false))goto END;
    if(sw(false,false))goto END;
    if(sw(false,true))goto END;
    cout<<-1<<endl;
    return 0;
END:
    for(ll i=0;i<N;i++){
        cout<<(res[i]?"S":"W");
    }
    cout<<endl;

}