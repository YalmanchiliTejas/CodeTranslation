#include <iostream>
#include<string>
#include<cmath>
#include<algorithm>
#include<cctype>
#include<queue>
#include<regex>
#include<stack>
#include<stdio.h>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
#define rep(i,n) for(int i=0;i<n;i++)
typedef int long long ll;
using namespace std;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main(){
    int n;
    cin>>n;
    int x=n*800;
    int y=(n/15)*200;
    cout<<x-y<<endl;
return 0;
}
