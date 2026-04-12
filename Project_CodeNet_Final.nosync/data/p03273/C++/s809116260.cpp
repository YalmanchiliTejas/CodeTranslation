    #include <bits/stdc++.h>
    using namespace std;
     
    int main() {
      int H, W;
      cin >> H >> W;
      
      vector<vector<char>> data(H, vector<char>(W));
      for (int i=0; i<H; i++){
        for (int j=0; j<W; j++){
          cin >> data.at(i).at(j);
        }
      }
      
      bool test;
      for (int i=0; i<H; i++){
        test =false;
        for (int j=0; j<W; j++){
          if (data.at(i).at(j)=='#'){
            test=true;
            break;
          }        
        }
        if (test) continue;
        else {
          for (int j=0; j<W; j++){
            data.at(i).at(j)='X';
          }
        }
      }
      
      
      for (int i=0; i<W; i++){
        test=false;
        for (int j=0; j<H; j++){
          if (data.at(j).at(i)=='#'){
            test=true;
            break;
          }        
        }
        if (test) continue;
        else {
          for (int j=0; j<H; j++){
            data.at(j).at(i)='X';
          }
        }
      }
      
      int count;
      for (int i=0; i<H; i++){
        count=0;
        for (int j=0; j<W; j++){
          if (data.at(i).at(j)=='X'){
            count++;
            continue;
          }
          else cout << data.at(i).at(j);
        }
        if(count==W) continue;
        else cout << endl;
      }

      
    }



      

      