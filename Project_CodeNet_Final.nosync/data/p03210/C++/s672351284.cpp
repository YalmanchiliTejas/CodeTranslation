#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include<climits>
#include <string>
#include <map>
#include <set>
#include <list>

#define ll long long
#define fornum(A,B,C) for(A=B;A<C;A++)

using namespace std;

/////////////////////////////////////////////////////
#define pll pair<ll,ll>

ll N;

int main(){
    scanf("%lld",&N);

    if(N==3||N==5||N==7){
        printf("YES");
    }else{
        printf("NO");
    }

    return 0;
}