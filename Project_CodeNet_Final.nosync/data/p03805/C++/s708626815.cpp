
#include <stdio.h>
#include <vector> 
#include <algorithm>
#include <functional>
#include <iostream>
#include <set> 
#include <unordered_map>
#include <queue>
void lookvec(std::vector<int> v);
void dim2vec(std::vector<std::vector<int> > G);
void lookset(std::set<int> s);
void lookset(std::set<std::pair<int,int>> s);
void sortvec(std::vector<int> &v);
void reversevec(std::vector<int> &v);
bool test(long long mini);

using namespace std;
class statusNode{
public:
	int now;
	set<int> visitedNode;
};

//隣接行列
int G[9][9];


int main(){

	for (int i = 0; i < 9; i++){
		for (int j = 0; j < 9; j++){
			G[i][j] = 0;
		}
	}

	int N, M,ans=0;
	queue<statusNode> q;
	cin >> N >> M;
	for (int i = 0; i < M; i++){
		int a, b;
		cin >> a >> b;
		G[a][b] = 1;
		G[b][a] = 1;
	}
	statusNode first;
	first.now = 1;
	q.push(first);
	while (q.size() != 0){
		statusNode nowNode = q.front();
		q.pop();
		if (nowNode.visitedNode.size() == N - 1){
			ans += 1;
			continue;
		}
		for (int i = 1; i < N+1;i++){
			if (G[nowNode.now][i] == 1 && nowNode.visitedNode.find(i)==nowNode.visitedNode.end()){
				//繋がっていて、そのパスでまだ未達だったら
				statusNode newnode = nowNode;
				newnode.visitedNode.insert(nowNode.now);
				newnode.now = i;
				q.push(newnode);

			}
		}
	}
	cout << ans << "\n";




	return 0;
}


//vectorの中身をみる関数
void lookvec(std::vector<int> v){
	printf("{");
	{for (int i = 0; i<v.size(); i++) printf("%d,", v[i]); }
	printf("}\n");
}
//二次元vectorの中身をみる関数
void dim2vec(std::vector<std::vector<int> > G){
	int i, j;
	for (i = 0; i < G.size(); i++){
		printf("{");
		for (j = 0; j < G[i].size(); j++){
			printf("%d",G[i][j]);
			if (j != G[i].size() - 1) printf(",");
		}
		printf("}\n");
	}
}

//setの中身を見る関数
void lookset(std::set<int> s){
	std::set< int >::iterator pos = s.begin();//先頭の要素を取得する
	while (pos != s.end()){//最後の要素に達するまでループ
		printf("%d,", *pos);//値を表示

		pos++;//一つ進める
	}
	printf("\n");
}

//setの中身を見る関数
void lookset(std::set<pair<int,int>> s){
	std::set< pair<int,int> >::iterator pos = s.begin();//先頭の要素を取得する
	while (pos != s.end()){//最後の要素に達するまでループ
		printf("<%d, %d>\n", pos->first,pos->second);//値を表示

		pos++;//一つ進める
	}
	printf("\n");
}
void sortvec(std::vector<int> &v){
	std::sort(v.begin(), v.end());
}
void reversevec(std::vector<int> &v){
	std::sort(v.begin(), v.end(), std::greater<int>());//降順ソート
}