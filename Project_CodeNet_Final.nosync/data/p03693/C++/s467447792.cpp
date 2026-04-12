#include <cstdlib>
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <map>
#define MOD 1000000007
#define INF 1000000000
typedef long long ll;
using namespace std;
typedef pair<int,int> P;

int main(void){
    int r,g,b;
    cin>>r>>g>>b;
    int num=r*100+g*10+b;
    if(num%4==0)printf("YES\n");
    else printf("NO\n");
    return 0;
}
