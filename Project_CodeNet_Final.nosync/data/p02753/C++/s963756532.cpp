#include<bits/stdc++.h>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;++A)
#define pii pair<int,int>
#define pll pair<ll,ll>

using namespace std;

/////////////////////////////////////////////////////

char S[10];
ll i, j, k;
int main(){
    scanf("%s", S);
    j = S[0];
    for (i = 1; S[i];++i){
        if(j!=S[i]){
            break;
        }
    }
    if(S[i]){
        printf("Yes");
    }else{
        printf("No");
    }
        return 0;
}