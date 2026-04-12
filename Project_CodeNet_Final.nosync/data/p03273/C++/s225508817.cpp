    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int H, W, count_h=0,count_v=0;
      cin >> H >> W;
  
      vector<vector<char>> data(H, vector<char>(W));
      for (int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++){
          cin >> data.at(i).at(j);
        }
      }
      
      vector<bool> judge_h(H,true), judge_v(W,true);
      
      for (int i = 0; i < H; i++) {
        for(int j = 0; j < W; j++){
      		 if(data.at(i).at(j) == '.')
              count_h += 1;
        }
        if(count_h == W)
        	judge_h.at(i) = false;
        count_h = 0;
      }
      
       for (int j = 0; j < W; j++) {
        for(int i = 0; i < H; i++){
      		 if(data.at(i).at(j) == '.')
              count_v += 1;
        }
        if(count_v == H)
        	judge_v.at(j) = false;
         count_v = 0;
      }
      
      for (int i = 0; i < H; i++) {
        if(judge_h.at(i))
         for(int j = 0; j < W; j++){
          if(judge_v.at(j))
            cout << data.at(i).at(j);    
         }
        else
          continue;
        cout << endl;
      }

  }
