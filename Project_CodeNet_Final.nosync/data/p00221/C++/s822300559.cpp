#include<iostream>
#include<queue>
#include<string>
#include<algorithm>
#include<vector>
#include<cstring>
using namespace std;

int main(){
  int m, n, s, i;
  char no[100];
  while(cin >> m >> n, m != 0 || n != 0) {
    queue<int> q;
    for(int j = 0; j < m; j++) q.push(j+1);
    i = 1;
    while(n--) {
      if(q.size() != 1) {
	cin >> no;
	int p = q.front(); q.pop();
	if(i%3 == 0 && i% 5 == 0) {
	  if(strcmp(no, "FizzBuzz") == 0) q.push(p);
	}
	else if(i % 3 == 0 && strcmp(no,"Fizz") == 0) q.push(p);
	else if(i % 5 == 0 && strcmp(no ,"Buzz") == 0)  q.push(p);
	else if(i % 3 != 0 && i % 5 != 0 && i == atoi(no)) q.push(p);
	i++;
      }
      else cin >> no;
    }
    
    vector<int> v(1050);
    while(q.size()) {
      v.push_back(q.front());
      q.pop();
    }
    sort(v.begin(), v.end());
    while(v.size()) {
      if(v[0]) {
	cout << v[0];
	if(v.size() - 1) cout << ' ';
      }
      v.erase(v.begin());
    }
    cout << endl;
  }
  return 0;
}