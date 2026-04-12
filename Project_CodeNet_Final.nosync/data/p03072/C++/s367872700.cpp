#include <bits/stdc++.h>
using namespace std;
int main(){
  int n,c,max;
  c=1;
  cin >> n;
  vector <int>a(n);
  for (int i=0;i<n;i++)
  cin >> a.at(i);
  max=a.at(0);
for(int i=1;i<n;i++){
    if(a.at(i)>=max){
        c++;
        max=a.at(i);
    }
}
  cout << c << endl;

}