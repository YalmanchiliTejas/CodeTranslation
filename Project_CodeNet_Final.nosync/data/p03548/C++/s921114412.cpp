/*
* @Author: 王文宇
* @Date:   2017-11-18 16:16:33
* @Last Modified by:   王文宇
* @Last Modified time: 2017-11-18 16:17:47
*/
#include <iostream>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int x,y,z;
	cin>>x>>y>>z;
	x-=z;
	cout<<x/(y+z)<<endl;
	return 0;
}