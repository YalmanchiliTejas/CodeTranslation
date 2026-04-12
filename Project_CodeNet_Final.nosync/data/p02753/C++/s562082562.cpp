#include  <iostream>
#include  <stdio.h>
#include <algorithm>
using namespace std;
#include <vector>
#define rep(i,n) for (int i = 0; i < (n) ; i++)
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define ll long long
#define ull unsigned long long
#define vint vector<int>
#define vll vector<ll>

//#include <stack>
//#include <queue>

/*
#include <math.h>
int standerd = int(pow(10.0,9.0)) + 7;
*/
string ans_Yes = "Yes"; 
string ans_No = "No"; 
string ans_yes = "yes"; 
string ans_no = "no"; 

ll A;
ll B;
ll C;
ll N;

int main(){

    string S;
    cin >> S;
    int countA=0;
    int countB=0;
    rep(ni,3){
        if(S.substr(ni,1)=="A"){
            countA++;
        }else if(S.substr(ni,1)=="B"){
            countB++;
        }
    }

    if(countA>0 && countB>0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }

    

}