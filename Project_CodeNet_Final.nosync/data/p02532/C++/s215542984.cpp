//"push hoge"と言われたらhogeを最後に入れ、"pop"と言われたら最後尾を取りだす。"quit"で終わり。
#include<iostream>
#include<deque>
#include<string>
#include<vector>
using namespace std;

int main(){
	string put;
	int p,p1,p2,n;
	char dummy;
	vector< vector<char> > col(100,vector<char>(1000));

	cin >> n;
	while(1){
		cin >> put;
		if(put == "push"){
			cin >> p >> dummy;
			col[p].push_back(dummy);
		}
		else if(put == "pop"){
			cin >> p;
			cout << col[p].back() << endl;
			col[p].pop_back();
		}
		else if(put == "move"){
			cin >> p1 >> p2;
			col[p2].push_back( col[p1].back());
			col[p1].pop_back();
		}
		else
			break;

	}


	return 0;
}