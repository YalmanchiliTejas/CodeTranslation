#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <fstream>
#include <map>
#include <vector>
//#include <unordered_map>
//#include <unordered_set>
#include <stack>
#include <set>
#include <queue>
#include <list>

using namespace std;

int main()
{
    int a,b,c;
    cin>>a>>b>>c;
    if((a*100+b*10+c)%4==0) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}
