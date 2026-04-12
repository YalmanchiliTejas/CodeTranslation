#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<utility>
#include<string>
#include<iomanip>
#include<queue> 
#include<cmath>
#include<utility>
#include<set>
using namespace std;
bool compare(int a, int b)
{
  return a > b;
}
int main()
{
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
  int a, b;
  cin >> a >> b;
  if(a==b)
  	cout << "Yes\n";
  else
  	cout << "No\n";
}
