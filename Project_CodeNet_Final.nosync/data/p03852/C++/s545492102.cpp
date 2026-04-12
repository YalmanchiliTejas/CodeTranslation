#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#define INF 10**9+7
using namespace std;
using Graph = vector<vector<int> >;//Graph graph(ノードの数)で生成できる

bool check(long long a,long long b,long long c){
    return true;
}

int main(){
    string S;
    cin >> S;
    if(S.at(0)=='a' || S.at(0)=='i' || S.at(0)=='u' || S.at(0)=='e' || S.at(0)=='o'){
        cout << "vowel" << endl;
    }else{
        cout << "consonant" << endl;
    }
    return 0;
}