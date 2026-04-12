#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N,M;
int G[9][9] = {{0}};
int main(){
	cin >> N >> M;
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		G[a][b] = 1;
		G[b][a] = 1;
	}
	vector<int> A = {1,2,3,4,5,6,7,8};
	int ans = 0;
	do{
		int c = 1;
		for(int i=0;i<N-1;i++){
			if(G[A[i]][A[i+1]]==1){
				//cout << c << endl;
				c++;
			}
			if(c==N) ans++;
		}
	}while(next_permutation(A.begin()+1,A.begin()+N));
	cout << ans << endl;
}