#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <cstdlib>
#include <algorithm>
#define NMAX (int )1e5+5

//コメントアウトするとdebug()を実行しない
#define DEBUG

using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	std::fill( (T*)array, (T*)(array+N), val );
}

typedef pair<int ,int > P;
typedef long long ll;

int N,ans = 0,M = -1;
char animal[4][NMAX],truth[NMAX];
char S[NMAX];
string dx[4] = {"SS","SW","WS","WW"};
bool check(int a,int b){
	if(truth[b] == 'o'){
		if(animal[a][b-1] == animal[a][b+1]){
			return true;
		}else{
			return false;
		}
	}else{
		if(animal[a][b-1] != animal[a][b+1]){
			return true;
		}else{
			return false;
		}
	}
}
void made(int a,int b){
	if(truth[b] == 'o'){
		animal[a][b+1] = animal[a][b-1];
	}else{
		if(animal[a][b-1] == 'S'){
			animal[a][b+1] = 'W';
		}else{
			animal[a][b+1] = 'S';
		}
	}
}

int solve(int a){
	animal[a][0] = dx[a][0];
	animal[a][1] = dx[a][1];
	animal[a][N] = animal[a][0];
	for (int i = 0; i < N; ++i)
	{
		if(animal[a][i] == 'S'){
			truth[i] = S[i];
		}else{
			if(S[i] == 'o'){
				truth[i] = 'x';
			}else{
				truth[i] = 'o';
			}
		}
		if(i == N-1){
			if(!check(a,i)){
				return -1;
			}else{
				if((truth[0] == 'o' && animal[a][N-1] != animal[a][1]) 
					|| (truth[0] == 'x' && animal[a][N-1] == animal[a][1])){
					return -1;
				}
			}
		}else if(i != 0){
			made(a,i);
		}
	}
	for (int j = 0; j < N; ++j)
	{
		cout << animal[a][j];
	}
	cout << "\n";
	return 0;
}

void debug(){

}

void answer(){
	cout << ans << "\n";
}

int main(){
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> S[i];
	}
	for (int i = 0; i < 4; ++i)
	{
		M = max(solve(i),M);
			if(M == 0){
				return 0;
			}
		}
		if(M == -1){
			cout << M << endl;
		}

	#ifdef DEBUG
		debug();
	#endif
	// answer();

		return 0;
	}