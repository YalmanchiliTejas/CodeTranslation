#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <utility>
#include <queue>
#include <stack>
#include <cmath>
#include <numeric>
#include <algorithm>

#define rep(i,j,k) for(int i=(int)j;i<(int)k;i++)
#define ll long long
#define all(v) ((v).begin(),(v).end())
#define Sort(v) sort(all(v))
using namespace std;
int day[12]={31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int n;
    int a;
    cin>>a;
    n+=a*100;
    cin>>a;
    n+=a*10;
    cin>>a;
    n+=a;
    if(n%4==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}



    

