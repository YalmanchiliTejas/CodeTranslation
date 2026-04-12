#include<iostream>
#include<string>
#include<algorithm>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <set>
#include <queue>
#include <stack>
#include <map>

using namespace std;
typedef int status;
typedef long long ll;
typedef unsigned long long ull;
const ull base = 343;
const int INF = int(1e9);
const ll INF1 = ll(1e15);
const int MAX = 200002;

int N;
ll a[MAX],b[MAX];

int main()
{
    cin>>N;
    for(int i = 1;i <= N;i++){
         cin>>a[i];
         b[i] = a[i];
    }
    sort(b+1,b+1+N);
    int t = N/2;
    for(int i = 1;i <= N;i++){
        if(a[i]<=b[t]){
            cout<<b[t+1]<<endl;
        }else{
            cout<<b[t]<<endl;
        }
    }


    return 0;
}
