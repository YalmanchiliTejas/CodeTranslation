//g++ -std=c++14 test.cpp -o test.out
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <cassert>
#include <algorithm>
#include <functional>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <map> 
#include <utility>
#include <limits.h>
#include <bitset>
#include <set>
using namespace std;
 
#define LL long long int
const LL INF = (LL)(1e18)+1;
const int INF_INT = 2147483647-1e6;
const LL mod = 1000000007ll;
 
int N;
LL A[100000];
 
int ans = 0;
 
void solve(){
	vector<vector<LL>> seq;//各数列を保管
	map<LL,queue<int>> seq_end;//例えばseq[5]の末尾が27ならseq_end[27]={5}
	multiset<LL> seq_tail_set;//各数列の末尾の数字を昇順に保管する

	seq.push_back(vector<LL>(1,A[0]));
	seq_end[A[0]].push(0);
	seq_tail_set.insert(A[0]);
	for(int i=1;i<N;i++){
		// cout <<endl <<  "------" << endl;
		// cout << "=now seqs=" << endl;
		// for(int i=0;i<seq.size();i++){
		// 	for(int j=0;j<seq[i].size();j++) cout << seq[i][j] << " ";
		// 	cout << endl;
		// }
		// cout << "==tail set==" << endl;
		auto nearest = seq_tail_set.lower_bound(A[i]);
		// for(auto val:seq_tail_set) cout << val << " ";
		// 		cout << endl;
		// cout << "==========" << endl;
		// printf("A[%d]=%lld\n",i,A[i]);
		if(nearest==seq_tail_set.begin() && (*nearest)>=A[i]){
			seq.push_back(vector<LL>(1,A[i]));
			seq_end[A[i]].push(seq.size()-1);
			seq_tail_set.insert(A[i]);
		}else{
			nearest--;
			int target_num = *nearest;
			// cout << "target_num=" << target_num << endl;
			int target_seq = seq_end[target_num].front();
			seq_end[target_num].pop();
			seq[target_seq].push_back(A[i]);
			seq_end[A[i]].push(target_seq);
			seq_tail_set.insert(A[i]);
			seq_tail_set.erase(seq_tail_set.find(target_num));//一個だけ消す
		}
	}
	// cout << "------" << endl;
	// 	for(int i=0;i<seq.size();i++){
	// 		for(int j=0;j<seq[i].size();j++) cout << seq[i][j] << " ";
	// 		cout << endl;
	// 	}
	ans = seq.size();
}
 
int main(){
	cin >> N;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
 
	solve();
 
	cout << ans << endl;
	return 0;
}