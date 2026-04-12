#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <map>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>

using namespace std;
using Pos = std::pair<int, int>;
//cout<<fixed<<std:cout<<fixed<<setprecision(2)<<Max<<endl;
constexpr int mod = 1e9 + 7;

int N;
string str;
vector<bool> a;//sheep->0, wolf->1

bool check(){
    //fill
    if(str[0]=='x'){
        a[1]=a[0]?a[N-1]:!a[N-1];
    }else{
        a[1]=a[0]?!a[N-1]:a[N-1];
    }
    for(int i=2;i<N-1;++i){
        if(str[i-1]=='x'){
            a[i]=a[i-1]?a[i-2]:!a[i-2];
        }else{
            a[i]=a[i-1]?!a[i-2]:a[i-2];
        }
    }

    //check
    if(a[N-2]){
        if(str[N-2]=='x'){
            if(a[N-1]!=a[N-3])return false;
        }else{
            if(a[N-1]==a[N-3])return false;
        }
    }else{
        if(str[N-2]=='x'){
            if(a[N-1]==a[N-3])return false;
        }else{
            if(a[N-1]!=a[N-3])return false;
        }
    }

    if(a[N-1]){
        if(str[N-1]=='x'){
            if(a[0]!=a[N-2])return false;
        }else{
            if(a[0]==a[N-2])return false;
        }
    }else{
        if(str[N-1]=='x'){
            if(a[0]==a[N-2])return false;
        }else{
            if(a[0]!=a[N-2])return false;
        }
    }
    return true;
}

int main() {
    cin>>N>>str;
    a.resize(N);

    a[0]=0;
    a[N-1]=0;
    if(check()){
        for(const auto& val:a){
            if(val)cout<<'W';
            else cout<<'S';
        }
        cout<<endl;
        return 0;
    }
    a[0]=0;
    a[N-1]=1;
    if(check()){
        for(const auto& val:a){
            if(val)cout<<'W';
            else cout<<'S';
        }
        cout<<endl;
        return 0;
    }
    a[0]=1;
    a[N-1]=0;
    if(check()){
        for(const auto& val:a){
            if(val)cout<<'W';
            else cout<<'S';
        }
        cout<<endl;
        return 0;
    }
    a[0]=1;
    a[N-1]=1;
    if(check()){
        for(const auto& val:a){
            if(val)cout<<'W';
            else cout<<'S';
        }
        cout<<endl;
        return 0;
    }
    cout<<-1<<endl;

    return 0;
}