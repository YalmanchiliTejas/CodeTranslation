#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <stdio.h>
#include <cmath>
#include <algorithm>
#include <string.h>
#define sf(n) scanf("%d",&n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define ll long long
#define mod 1000000007
#define INF 400000
using namespace std;
int main(){
    int n;sf(n);
    int a[30]={0};
    for(int i=0;i<n;i++){
        sf(a[i]);
    }
    int mmax=0;
    int cnt=0;
    for(int i=0;i<n;i++){
        if(a[i]>=mmax){
            cnt++;mmax=a[i];
        }
    }
    printf("%d\n",cnt);
}
