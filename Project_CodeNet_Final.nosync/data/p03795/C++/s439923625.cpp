#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
//deque/functional/iterator/list/map/memory/numeric/queue/set/stack/utility/vector
//#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
    int a,b,n;
    cin>>n;
    b=n/15;
    b=b*200;
    a=n*800;
    cout<<a-b<<endl;
return 0;
}
