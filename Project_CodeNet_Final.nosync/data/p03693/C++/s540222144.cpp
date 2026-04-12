#include <algorithm>
#include <iostream>
#include <cstring>
#include <cassert>
#include <fstream>
#include <climits>
#include <cstdio>
#include <vector>
#include <string>
#include <memory>
#include <queue>
#include <cmath>
#include <list>
#include <set>
#include <map>


using namespace std;

typedef long long ll;
typedef pair<int,int> pii;


int main()
{
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    int res=a*100+b*10+c;
    if(res%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
