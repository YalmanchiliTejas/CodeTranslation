//
//  main.cpp
//  ABC154E
#include <iostream>
#include<vector>
#include<string>
#include<stdio.h>
using namespace std;
int main(int argc, const char * argv[]) {
    string S;
    cin >>S;
    int K;
    cin >> K;
    unsigned long length=S.length(); // 入力された数値の桁数
    vector<vector<int>>dp1(length+1,vector<int>(4));
    vector<vector<int>>dp0(length+1,vector<int>(4));
    // 初期値
    dp1.at(0).at(0)=0;
    dp1.at(0).at(1)=0;
    dp1.at(0).at(2)=0;
    dp1.at(0).at(3)=0;
    dp0.at(0).at(0)=1;
    dp0.at(0).at(1)=0;
    dp0.at(0).at(2)=0;
    dp0.at(0).at(3)=0;
    
    dp0.at(1).at(0)=1; // 入力した数値の右端は必ず０ではない数字
    
    vector<int>n(length+1);
    n.at(0)=0;
    for (int i=1; i<=length; i++) {
        n.at(i) =S[i-1]-'0'; // 各桁の数値をnにセット
    }
    int r1; // 繰り返しの数
    int r2;
    for (int i=1; i<=length; i++) {
        if(n.at(i)>0){
            r1=n.at(i)-1;
            r2=1;
        }else{
            r1=0;
            r2=0;
        }
        dp1.at(i).at(0)=1;
        dp1.at(i).at(1)=dp1.at(i-1).at(0)*9+dp1.at(i-1).at(1)+dp0.at(i-1).at(0)*r1+dp0.at(i-1).at(1)*r2;
        dp1.at(i).at(2)=dp1.at(i-1).at(1)*9+dp1.at(i-1).at(2)+dp0.at(i-1).at(1)*r1+dp0.at(i-1).at(2)*r2;
        dp1.at(i).at(3)=dp1.at(i-1).at(2)*9+dp1.at(i-1).at(3)+dp0.at(i-1).at(2)*r1+dp0.at(i-1).at(3)*r2;

        if(n.at(i)==0){
            dp0.at(i).at(1)=dp0.at(i-1).at(1);
        } else{
            dp0.at(i).at(1)=dp0.at(i-1).at(0);
            dp0.at(i).at(0)=0;
        }
        if(n.at(i)==0){
            dp0.at(i).at(2)=dp0.at(i-1).at(2);
        }else{
            dp0.at(i).at(2)=dp0.at(i-1).at(1);
        }
        if (n.at(i)==0) {
            dp0.at(i).at(3)=dp0.at(i-1).at(3);
        }else{
            dp0.at(i).at(3)=dp0.at(i-1).at(2);
        }
    }
    int ans=dp1.at(length).at(K)+dp0.at(length).at(K);
    cout<<ans<<endl;
    
    return 0;
}
