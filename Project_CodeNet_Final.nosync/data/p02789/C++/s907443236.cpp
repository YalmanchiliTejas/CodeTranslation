/*
	Created by Faisal Ahmed
*/

#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long int ll;
typedef long double ld;

bool visited[100010];
int p[100010];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);cout.tie(NULL);
	
	int n, m;
	
	cin >> n >> m;
	
	if(m >= n){
		cout << "Yes" << endl;
	}
	else{
		cout << "No" << endl;
	}
	
	return 0;
} 