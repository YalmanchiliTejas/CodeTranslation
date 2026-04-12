#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <queue>
typedef long long ll;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define mod 1000000007

string divide[4] = {"dream","dreamer","erase","eraser"};

int main(){
	int N; //山の数
	cin >> N;
	vector<int> H(N); //山の高さ
	for(int i = 0; i < N; i++){
		cin >> H[i]; //高さを順番に入力
	}
	//1番目の山の高さと同じかそれより高い山を数える
	int count = 0;
	int max = 0; //一番高い山の高さを入れる変数
	for(int i = 0; i < N; i++){
		if(max < H[i]){
			max = H[i];
		}
		if(max <= H[i]){
			count++;
		}
	}
	cout << count << endl;
}