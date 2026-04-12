#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
using namespace std;
using ll = long long;
#define Ma_PI 3.141592653589793
#define eps 0.00000001
#define LONG_INF 3000000000000000000
#define rep(i,n) for(long long i = 0;i < n;++i)    
#define seg_size 524288

int k;
int choose(int n,int k,int nine){
    if(n<k)return 0;
    int a=1;
    for(int i=0;i<nine;i++){
        a*=9;
    }
    if(k==0)return a;
    if(k==1)return n*a;
    else return (n-1)*n/2*a;
}
void cn(string &n,int cnt){
    //cout<<cnt<<endl;
    rep(i,n.size()){
        if(cnt==0)n[i]='9';
        else if(n[i]!='0'){
            cnt--;
            if(cnt==0)n[i]-=1;
        }
        //cout<<i<<"::"<<n<<endl;
    }
        
    if(n[0]=='0'){
        n.erase(0,1);
    }
}
int main(){
    string n;
    
    cin>>n;
    cin>>k;
    int cnt=0;
    rep(i,n.size()){
        if(n[i]!='0')cnt++;
    }
    //cout<<cnt<<" ";
    if(cnt<k)cn(n,cnt);
   // cout<<n<<endl;

    cnt=0;
    rep(i,n.size()){
        if(n[i]!='0')cnt++;
    }
    if(cnt<k)cn(n,cnt-1);
    //cout<<"n="<<n<<endl;
    if(k>n.size()){
        cout<<0<<endl;
        return 0;
    }
    int keta=0;
    int t=n.size();
    rep(i,t){
        if(i==0||k>i) continue;
        
        keta+=choose(i-1,k-1,k);
    
    }
    
    //cout<<n[0]<<" "<<n[1]<<endl;
    //cout<< "t="<<t<<endl;
    vector<int>fr(k),m(k);
   
    for(int i=0;i<k;i++){
        for(int j=0;j<n.size();j++){
            if(n[j]!='0'){
                fr[i]=n[j]-'0';
                m[i]=j+1;
                i++;
                if (i == k)break;
            }
        }  
    }
    int ans=keta;
    // cout<<keta<<endl;
    //cout<<m[0]<<" "<<m[1]<<endl;
    // cout<<fr[0]<<" "<<fr[1]<<endl;

    rep(i,k){
        ans+=(fr[i]-1)*choose(t-m[i],k-i-1,k-i-1);
    }
    //cout<<ans<<endl;
    rep(i,k-1){
        ans+=choose(t-m[i+1],k-1-i,k-1-i);
    }
    ans++;
    cout<<ans<<endl;
    return 0;
}