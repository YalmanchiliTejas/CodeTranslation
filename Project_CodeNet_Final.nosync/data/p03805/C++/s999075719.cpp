#include <iostream>
using namespace std;

int cp[10], P[10][10];

int search(int i, int j){
    cp[i]=0;
    int S=0;
    bool all=true;
    for(int k=1; k<=j; ++k){
        if(cp[k]){
            all=false;
            if(P[i][k]) S += search(k, j);
        }
    }
    if(all) ++S;
    cp[i]=1;
    return S;
}

int main() {
	int N, M; cin >> N >> M;
	for(int i=0; i<=N; ++i) for(int j=1; j<=N; ++j) P[i][j]=0;
	int a, b;
	for(int i=0; i<M; ++i){
	    cin >> a >> b;
	    ++P[a][b];
	    ++P[b][a];
	}
	for(int i=1; i<=N; ++i) cp[i]=1;
	cout << search(1, N) << endl;
	return 0;
}
