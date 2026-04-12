#include<iostream>
#include<vector>
#include<cstdio>
#include<string>
#include<numeric>
#include<algorithm>
#include<complex>
#include<queue>
#include<stdlib.h>
#include<map>
#include<cmath>
#include<stdio.h>
#include<stdlib.h>
#include<set>

#define ll long long int
#define MOD 1000000007
#define pb push_back
#define ub upper_bound
#define lb lower_bound

using namespace std;

int main(){
    int N;
    int s[101];
    while(1){
        cin >> N;
        if(N==0){
            break;
        }
        for(int i=0;i<N;i++){
            cin >> s[i];
        }
        int ans=0;
        int MAX=s[0],min=s[0];
        for(int i=0;i<N;i++){
            if(MAX<s[i]){
                MAX=s[i];
            }
            if(min>s[i]){
                min=s[i];
            }
        }
        for(int i=0;i<N;i++){
            ans+=s[i];
        }
        ans-=MAX;
        ans-=min;
        cout << ans/(N-2) << endl;
    }
    return 0;
}

