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
const int MAX = 200002;

ll N,M;
char a[MAX];

int main()
{
    cin>>N>>M;
    ll sum = 0;
    if(M==0)cout<<N*N<<endl;
    else {
        sum += ((N-M)*(N-M+1))/2;
        for(int i = M+1;i <=N;i++){
        ll temp = (N-i+1)/i*(i-M);
        ll temp2 = ((N-i+1)%i-M)<0?0:((N-i+1)%i-M);
        sum += temp+temp2;
    }
    cout<<sum<<endl;

    }

    return 0;
}
