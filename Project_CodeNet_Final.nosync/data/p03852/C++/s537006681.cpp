#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cstdio>
using namespace std;
#define NIN(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define NINJ(i,n) for((i)=1;(i)<=(int)(n);(i)++)
#define pb push_back
#define LL long long
#define ff first
#define ss second
#define pp pair<double,double>
#define pt pair<double,pair<int,int>>

int pr[200005];

int fnd(int r)
{
    return (pr[r]==r) ? r :  pr[r]=fnd(pr[r]);
}
int main()
{
    char c;
    cin>>c;
    if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
        cout<<"vowel"<<endl;
    else
        cout<<"consonant"<<endl;
    return 0;
}
