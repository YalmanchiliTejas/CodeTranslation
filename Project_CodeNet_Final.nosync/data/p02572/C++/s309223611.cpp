#include <bits/stdc++.h>
#include <iostream>
#include <math.h>    //pow(x,y)=x^y 99999とかの場合+1するif文
#include <algorithm> //sort(a.begin(), a.end());reverse(a.begin(), a.end());
#define rep(init, i, n) for (int i = init; i < (n); i++)
#define ll long long
#define rev(s) reverse(s.begin(), s.end())
#define sor(v) sort(v.begin(), v.end())
//コード自動整形 Shift + Option + F @vscode
using namespace std;

/////main/////
int main()
{
    ll N;
    cin >> N;

    vector<ll> A(N);
    vector<ll> summod(N-1);

    rep(0, i, N)
    {
        cin >> A.at(i);
    }

    ll output = 0;
    ll modbs = 1000000007;
    
    summod.at(N-2) = A.at(N-1);

    for(int i = N-3; i >= 0; --i){
        summod.at(i) = summod.at(i+1) + A.at(i+1);
        //cout<<"summod1.at("<<i<<")"<<summod.at(i)<<endl;//
        summod.at(i) %= modbs; 
    }
    //rep(0,i,N-1){//
        //cout<<"summod.at("<<i<<")"<<summod.at(i)<<endl;//
    //}//

    rep(0,i,N-1){
        output += A.at(i)*summod.at(i);
        //cout<<"output"<<output<<endl;//
        output %= modbs;
        //cout<<"outputmoded"<<output<<endl;//
    }

    cout<<output<<endl;

}
/////main/////

/////function/////