/* ************************************************************************
	> File Name: a.cpp
	> Author: caowushang
	> Mail: 15630929347@163.com 
	> Created Time: 2017年02月18日 星期六 20时03分11秒
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("in","r",stdin);
	//freopen("out","w",stdout);
	int n;
	cin >> n;
	int x=n/15;
	int ans=n*800-x*200;
	cout << ans << endl;
	return 0;
}
