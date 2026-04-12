#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,op=0;
    long long x=0LL,ai,t1;
    cin>>n;
    deque<long long> s;
    for(int i=0;i<n;i++){
        cin>>ai;
        s.push_back(ai);
        while(s.size()>2&&(s[s.size()-2]>=s[s.size()-1])&&(s[s.size()-2]>=s[s.size()-3])){
                t1 = s[s.size()-1]+s[s.size()-3]-s[s.size()-2];
                s.pop_back();
                s.pop_back();
                s.pop_back();
                s.push_back(t1);
        }
    }
    int sign = 1;
    while(s.size()){
        if(s.back()>s.front()){
            x = x + sign*s.back();
            s.pop_back();
        }else{
            x = x + sign*s.front();
            s.pop_front();
        }
        sign = -sign;
    }
    cout<<x<<"\n";
    return 0;
}