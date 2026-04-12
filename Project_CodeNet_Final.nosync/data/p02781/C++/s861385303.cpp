#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll=long long;
using vi=vector<int>;
int ctoi(char c){return (int)c-(int)'0';}
int main() {
    string N;
    cin>>N;
    int d=N.size();
    int K;cin>>K;
    int ans=0;
    if(K==1){
        ans=9*(d-1);
        ans+=ctoi(N[0]);
    }else if(K==2){
        if(d<2){
            cout<<0<<endl;
            return 0;
        }
        ans+=9*9*(d-1)*(d-2)/2;
        ans+=(ctoi(N[0])-1)*(d-1)*9;
        int i=1;
        while(i<d&&ctoi(N[i])==0)i++;
        if(i!=d){
            ans+=(d-1-i)*9;
            ans+=ctoi(N[i]);
        }
    }else if(K==3){
        if(d<3){
            cout<<0<<endl;
            return 0;
        }
        ans+=9*9*9*((d-3)*(d-2)*(2*d-5)/6+(d-3)*(d-2)/2)/2;
        ans+=(ctoi(N[0])-1)*(d-1)*(d-2)/2*9*9;
        int i=1;
        while(i<d&&ctoi(N[i])==0)i++;
        if(i<d){
            ans+=(ctoi(N[i])-1)*(d-1-i)*9;
            ans+=(d-i-1)*(d-i-2)/2*9*9;
        }
        int j=i+1;
        while(j<d&&ctoi(N[j])==0)j++;
        if(j<d){        
            ans+=(d-1-j)*9;
            ans+=ctoi(N[2]);
        }
    }
    cout<<ans<<endl;
}