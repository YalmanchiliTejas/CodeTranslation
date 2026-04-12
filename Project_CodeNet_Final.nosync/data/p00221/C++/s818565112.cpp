#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

int CheckAnswer(int, string);
int Atoi(const string);

int main(){
  int i, j, m, n;
  string s;
  vector<int> data;

  while(1){
    cin >> m >> n;
    if(m == 0 && n == 0) break;

    for(i=0; i<m; ++i)
      data.push_back(i+1);

    for(i=0, j=0; i<n; ++i, ++j){
      cin >> s;

      if(data.size() != 1){
	if(CheckAnswer(i+1, s) == 0){
	  data.erase(data.begin()+j);
	  --j;
	}
	if(j >= data.size()-1) j = -1;
      }
    }

    for(i=0; i<data.size()-1; ++i)
      cout << data[i] << " ";
    cout << data[data.size()-1] << endl;

    data.clear();
  }

  return 0;
}

int CheckAnswer(int n, string s){
  int x, ans = 0;

  if(n%15 == 0){
    if(s == "FizzBuzz") ans = 1;
  }else if(n%5 == 0){
    if(s == "Buzz") ans = 1;
  }else if(n%3 == 0){
    if(s == "Fizz") ans = 1;
  }else{
    if(s != "FizzBuzz" || s != "Buzz" || s != "Fizz"){
      x = Atoi(s);
      if(x == n) ans = 1;
    }
  }

  return ans;
}

int Atoi(const string c){
  int i, x=0, digit=1;

  for(i = c.size()-1; i >= 0; --i){
    x = x + (c[i] - 48) * digit;
    digit *= 10;
  }
  return x;
}