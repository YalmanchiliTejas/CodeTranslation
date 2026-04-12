#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,w;
    cin>>n>>w;
    vector<vector<char> >board(n, vector<char>(w));
    for(int i = 0;i < n;i++){
       for(int j = 0;j < w;j++){
          cin>>board[i][j];
       }
    }
    vector<vector<char> > rows;
    for(const auto &row: board) {
       if(find(row.begin(),row.end(),'#' ) != row.end()) {
       	 rows.push_back(row);
       }
    }
    vector<int> colls;
    for(int col = 0;col < w;col++){
       bool shouldAdd = false;
       for(int i = 0,n = rows.size();i < n;i++) {
          if(rows[i][col] == '#') {
	    shouldAdd = true;
	    break;
	  }
       }
       if(shouldAdd) colls.push_back(col);
    }
    vector<string> ans;
    for(const auto &row: rows){
       string ansrow;
       for(const int &col: colls){
          ansrow.push_back(row[col]);
       }
       ans.push_back(ansrow);
    }
    for(const auto ansRow: ans) cout<<ansRow<<endl;
    return 0;
}
