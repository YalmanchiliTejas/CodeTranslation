#include <iostream>
#include <vector>
#include <tuple>
#include <string>

using namespace std;

int main(void){
  string S;
  string P;
  cin >> S;
  cin >> P;

  int search = 0;
  int count = 0;
  bool finish = false;
  int preserch = 0;
  bool many_same_char = false;
  vector<tuple<int, int>> st;

  for(int ptr = 0 ; !finish ; ptr++){
    if( S[ptr] == P[search] ){
      preserch = search;
      if( search >= P.length() - 1 ){
        int oldcount = count;
        for(int subptr = ptr ; subptr < S.length() ; subptr++){
          if( S[subptr] == P[search]){
            count++;
          }
        }
        if( count - oldcount == 1){
          if( many_same_char ){
            count = 2000;
          }else{
            count = 1;
          }
          finish = true;
        }


        if(!st.empty()){
          tuple<int,int> t = st.back();
          st.pop_back();
          ptr = get<0>(t);
          search = get<1>(t);
        }else{
          finish = true;
        }

        if(count >= 2){
          finish = true;
        }
      }else{
          st.push_back(make_tuple(ptr, search));
          search++;
      }
    }else if( ptr >= S.length() - 1 ){
      finish = true;
    }else if( S[ptr] == P[preserch] ){
      many_same_char = true;
    }


  }

  if( count == 1 ){
    cout << "yes" << endl;
  }else{
    cout << "no" << endl;
  }

  return 0;

}