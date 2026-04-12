//
//  main.cpp
//  ABC124
//
//  Created by hiroaki on 2019/05/07.
//  Copyright © 2019年 hiroaki. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath> 
#include <tuple>
#include <bitset>
#include<string>
//pair sort firstに揃う

#define int long long
#define double long double
#define Rap(n,i) for(int (i)=0;(i)<(n);(i)++)
#define Pr(n) cout<<n<<endl;
#define PairV vector<pair<int , int> >
#define F first
#define S second
#define Vector1 vector<int>
#define VectorS vector<string>
#define vector2 vector<vector<int> >
#define index(v,x) find((v).begin(), (v).end(), (x))-(v).begin()
#define ctoi(c) (int)(c-'0')
#define incin(n) int (n); cin>>(n);
#define incin2(n,m) int (n),(m); cin >> (n)>>(m);
#define stcin(s) string (s); cin>>(s);
#define all(v) (v).begin() , (v).end()
namespace Mathf
{
    const int INF = 1000000000000;
    const double PI = 3.14159274;
    const double Rad2Deg = 57.29578;
    const double log2(double a,double b);
    const double log2(double a,double b){
        return log(b)/log(a);
    }
} // namespace Mathf

using namespace std;

int MD(pair<int,int> a,pair<int,int> b){//ManhattanDisRance
    return abs(a.first-b.first) + abs(a.second-b.second);
}
int MOD(int a,int b){
    return abs(a%b);
}
template <typename T1,typename T2> bool Comp (pair<T1,T2> a,pair<T1,T2> b){
    if(a.first!=b.first){
        return a.first<b.first;//first昇順
    }
    if(a.second!=b.second){
        return a.second > b.second;//second降順
    }else{
        return  true;
    }
}
double Dis(pair<int,int> a,pair<int,int> b){
    return sqrt((a.first-b.first)*(a.first-b.first)+(a.second-b.second)*(a.second-b.second));
}
int Step(int N){
    if(N==0){
        return 1;
    }else{
        return N*Step(N-1);
    }
}
int Pemu(int n,int r){
    int ans = n;
    for(int i=0;i<r;i++){
        ans*=(ans-i);
    }
    return ans;
}
int Comb(int n,int m){
    int ans=n;
    for(int i=0;i<m;m++){
        ans*=(ans-i);
    }
    return ans/Step(m);
}
int Digit(int x){
    string ss = to_string(x);
    int size = ss.size();
    int sum = 0;
    for(int i=0;i<size;i++){
        sum+=ctoi(ss[i]);
    }
    return sum;
}
signed  main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    int a,b,c,x,y;
    cin>>a>>b>>c>>x>>y;
    int cost = 0;

    if (2*c < a+b){
        if(x>y){
            if(2*c<a){
                cout<<2*c*x<<endl;
            }else{
                cout<<2*c*y+a*(x-y)<<endl;
            }
        }else{
            if(2*c<b){
                cout<<2*c*y<<endl;
            }else{
                cout<<2*c*x+b*(y-x)<<endl;
            }
        }
    }else{
        cout<<a*x+b*y<<endl;
    }
    
    return 0;
}