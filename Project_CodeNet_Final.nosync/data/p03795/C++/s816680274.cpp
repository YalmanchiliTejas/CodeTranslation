#include <cstdio>
#include <iostream>

using namespace std;

int main()
{
int n;
cin >> n;
int ans = n *800;
int k = n/15;
ans -= k *200;
cout << ans <<endl;
}