
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <math.h>
#include <utility>
#include <set>
#include <map>
#include <cstring>
#include <cstdio>
#include <stack>
#include <cmath>
#define INF 1000000000
#define rep(i,n) for(int i =0;i<n;i++)
using namespace std;
typedef long long int ll;
typedef pair<int, int> i_i;


int main(){
    string S;
    int n;
    cin >> S >> n;
    int a=0,b=0;
    vector<int> cal1(1000),cal2(1000);
    int c1=0,c2=0;
    for (int i=0; i<S.length(); i++) {
        if (S[i]=='+') {
            int c = cal1[c1];
            int num = c + (int)S[i+1]-(int)'0';
            cal1[c1]=num;
            i++;
            continue;
        }
        if (S[i]=='*') {
            int a = cal1[c1];
            int num = a *((int)S[i+1]-(int)'0');
            cal1[c1]=num;
            i++;
            continue;
        }
        c1++;
        cal1[c1]= (int)S[i]-(int)'0';
    }
    a = cal1[c1];
    for (int i=0; i<S.length(); i++) {
        if (S[i]=='+') {
            c2++;
            cal2[c2]=-1;
            continue;
        }
        if (S[i]=='*') {
            int a = cal2[c2];
            int num = a *((int)S[i+1]-(int)'0');
            cal2[c2]=num;
            i++;
            continue;
        }
        c2++;
        cal2[c2] = (int)S[i]-(int)'0';
    }
    while (c2>0) {
        if(cal2[c2]!=-1) {
            b+= cal2[c2];
        }
        c2--;
    }
    if (a==n and b == n) {
        cout <<"U"<<endl;
    }else{
        if (b==n) {
            cout << "M"<<endl;
        }else{
            if (a==n) {
                cout << "L"<<endl;
            }else{
                cout << "I"<<endl;
            }
        }
    }
}