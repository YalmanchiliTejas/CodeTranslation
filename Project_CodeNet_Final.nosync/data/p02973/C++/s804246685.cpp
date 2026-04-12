#include<iostream>
#include<set>
//#include<algorithm>

using namespace std;

void print(multiset<int>& col){
  for(multiset<int>::iterator it = col.begin(); it != col.end();it++){ 
    cout << *it << " ";    
  }
  cout << endl;
}

int main(){
  int n,a;
  cin >> n;
  multiset<int> col{-1};

  for(int i = 0; i < n; i++){
    cin >> a;
    multiset<int>::iterator it = col.lower_bound(a);
    if(it == col.begin() ){
      col.insert(a);
      //      cout << "insert" << endl;
      //      print(col);
    }else{
      it--;
      col.erase(it);
      col.insert(a);
      //      cout << "change" <<endl;
      //      print(col);
    }
  }

  cout << col.size() << endl;
  
}
