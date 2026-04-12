#include<iostream>
#include<vector>
#include<algorithm>
#include<numeric>
using namespace std;
int main()
{
	int n,m,ans=0;
	cin>>n>>m;
	
	vector<vector<int>> v1(m, vector<int>(2));//どこからどこへ辺が伸びているかを管理する
	for(int i=0;i<m;++i){
		for(int j=0;j<2;++j){
			cin>>v1[i][j];
		}
	}
	
	vector<vector<int>> v2(n+1, vector<int>(n+1));//頂点１→頂点２のとき、頂点２→頂点１のときにそれぞれ１にする
	for(int i=0;i<m;++i){
		for(int j=0;j<(n-1);++j){
			v2[v1[i][0]][v1[i][1]] = v2[v1[i][1]][v1[i][0]] = 1;
		}
	}
	
	vector<int>v3(n-1);
	iota(v3.begin(),v3.end(),0);//for(int i=0;i<n;++i)v[i]=i;と同じ
	
	do{
		if(v2[1][v3[0]+2] == 1){
			if(n==2){
				ans++;
				break;
			}else{
				for(int i=0;i<(n-2);++i){
					if(v2[v3[i]+2][v3[i+1]+2] == 1){
						if(i == n-3) ++ans;
					}else break;
				}
			}
		}
	}while(next_permutation(v3.begin(),v3.end()));
	cout<<ans<<endl;
	return 0;
}