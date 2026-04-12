#include<iostream>
using namespace std;

const int Nmax=8;
bool check_route(bool route[][Nmax],bool node[],int now);
bool check_node(bool node[]);
void print_route(bool route[][Nmax]);
int count=0;


int main(void){

//初期データの入力
	int N,M;
	cin>>N>>M;

	bool route[Nmax][Nmax];
	bool node[Nmax];

	int n1,n2;

	//ノードを訪れたかを初期化 範囲外のノードは最初からtrue
	for(int i=0;i<Nmax;i++){
		if(i<N) node[i]=false;
		else node[i]=true;
	}

	//ルートの初期化
	for(n1=0;n1<Nmax;n1++){
		for(n2=0;n2<Nmax;n2++){
			route[n1][n2]=false;
		}
	}

	//ルートの登録
	for(int i=0;i<M;i++){
		cin>>n1>>n2;
		route[n1-1][n2-1]=true;
		route[n2-1][n1-1]=true;
		
	}

//データ入力終了

	check_route(route,node,0);

	cout<<count<<endl;

}

//すべてのnodeに到達したならtrueを返す
bool check_node(bool node[]){

	for(int i=0;i<Nmax;i++){
		if(node[i]==false) return false;
	}

	return true;

}



//ルートの探索関数
bool check_route(bool route[][Nmax],bool node[],int now){

	int next;

	//現在地を到着済みに
	node[now]=true;

	//もしすべてのノードに到達したならば正解個数を1増やし終了
	if(check_node(node)==true){
		count++;
	}

	//もし行ってない場所にいける経路があるなら移動
	for(next=0;next<Nmax;next++){
		if( (node[next]==false) && (route[now][next])==true){
			route[now][next]=route[next][now]=false;
			check_route(route,node,next);
			route[now][next]=route[next][now]=true;
		}
	}

	//関数を抜けるときは到達をもとに戻しておく
	node[now]=false;
	return false;
}

void print_route(bool route[][Nmax]){

	for(int i=0;i<Nmax;i++){
		for(int j=0;j<Nmax;j++){
			cout<<route[i][j];
		}
		cout<<endl;
	}


}
