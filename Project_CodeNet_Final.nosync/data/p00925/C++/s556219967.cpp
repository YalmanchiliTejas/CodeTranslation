#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int mod=1000000007,MAX=3005,INF=1<<29;
typedef string::const_iterator State;

int expression1(State &begin);
int expression2(State &begin);
int term(State &begin);
int number(State &begin);

int expression1(State &begin){
    int ret=number(begin);
    
    for(;;){
        if(*begin=='+') ret+=number(++begin);
        else if(*begin=='*') ret*=number(++begin);
        else break;
    }
    
    return ret;
}

int expression2(State &begin){
    int ret=term(begin);
    
    for(;;){
        if(*begin=='+') ret+=term(++begin);
        else break;
    }
    
    return ret;
}

int term(State &begin){
    int ret=number(begin);
    
    for(;;){
        if(*begin=='*') ret*=number(++begin);
        else break;
    }
    
    return ret;
}

int number(State &begin){
    int ret=0;
    
    while(isdigit(*begin)){
        ret*=10;
        ret+=*begin-'0';
        
        begin++;
    }
    
    return ret;
}
 
int main(){
    
    std::ifstream in("text.txt");
    std::cin.rdbuf(in.rdbuf());
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    string S;cin>>S;
    
    State a=S.begin(),b=a;
    int A=expression1(a),B=expression2(b);
    
    int T;cin>>T;
    
    if(A==T&&B==T) cout<<"U"<<endl;
    else if(A==T) cout<<"L"<<endl;
    else if(B==T) cout<<"M"<<endl;
    else cout<<"I"<<endl;
}

