#include <bits/stdc++.h>
using namespace std;

int main() {
  int H, W;
  cin >> H >> W;
  
  vector<vector<char>> data(H, vector<char>(W));
  
  /*
  for(int h = 0; h<H; h++){
    for(int w = 0; w<W; w++){
      cin >> data.at(h).at(w);//データ取得 ↓でやることにした(trueとかfalseのとこ)
    }
  }
  */
  /*取得したデータを表示
  for(int h = 0; h<H; h++){
    for(int w = 0; w<W; w++){
      cout << data.at(h).at(w);
      if(w == W-1) cout<<endl;
    }
  }
  */
  
  vector<bool> row(H, false);//すべてfalseで初期化して，下で#がある行はtrueにする
  vector<bool> col(W, false);//すべてfalseで初期化して，下で#がある列はtrueにする
  
  for(int h=0; h<H; h++){
    for(int w=0; w<W; w++){
      cin >> data.at(h).at(w);//データ取得
      if(data.at(h).at(w) == '#'){
        row.at(h) = true;
        col.at(w) = true;
      }
    }
  }
    
  int num_col = 0;//表示すべき最終列がいくつかを今から求める
  for(int w = 0; w<W ; w++){
    if(col.at(w) == true) num_col = w+1;
  }
  //cout << "num_col: " << num_col<< endl;
    
  for(int h=0; h<H; h++){
    if(row.at(h) == false) continue;
    
    for(int w=0; w<num_col; w++){
      if(col.at(w) == false) continue;
      
      cout << data.at(h).at(w);
      if(w==num_col-1) cout<<endl;
    }
  }
    
        
  
  
  /*
  int N, M;
  cin >> N >> M;
  vector<int> A(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> A.at(i) >> B.at(i);
  }

  vector<vector<char>> data(N, vector<char>(N));
  
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      data.at(i).at(j) = '-';
    }
  }
  
  //cout <<N<<" " << A.size()<<" "<<B.size()<<endl;
  
  for(int m=0; m<M; m++)
  {
    data.at(A.at(m)-1).at(B.at(m)-1) = 'o';
    data.at(B.at(m)-1).at(A.at(m)-1) = 'x';
  }
  
   
  for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
      cout << data.at(i).at(j);
      if(j==N-1) cout<<endl;
      else  cout<<' ';
    }
  }
  */
}
