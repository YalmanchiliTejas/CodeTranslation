#include<bits/stdc++.h>

using namespace std;

typedef long long int Int;

bool dist[8][8];



int main(void)
{
    int n,m;
    vector<int> a;

    cin>>n>>m;
    for(int i = 0;i < 8;i++) {
	for(int j = 0;j < 8;j++) {
	    dist[i][j] = false;
	}
    }

    for(int i = 0;i < m;i++)
    {
	int x,y;
	cin>>x>>y;
	x--;
	y--;
	dist[x][y] = true;
	dist[y][x] = true;
    }

    for(int i = 0;i < n;i++)
	a.push_back(i);

    Int ans = 0;
    do
    {
	if(a[0] != 0)
	    continue;

	bool flag = true;
	for(int i = 0;i < n-1;i++)
	    if(!dist[a[i]][a[i+1]])
		flag = false;

	if(flag)
	    ans++;
	    
    }while(next_permutation(a.begin(),a.end()));

    cout<<ans<<endl;

    return 0;
}
