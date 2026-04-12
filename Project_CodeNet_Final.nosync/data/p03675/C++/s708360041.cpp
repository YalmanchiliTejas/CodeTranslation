#include<iostream>
#include<vector>

using namespace std;

int main(){

  vector <long long> d;
  int n;
  long long a;
  cin >> n;
  for(int i = 0;i < n;i++){
    cin >> a;
    d.push_back(a);
  }
  if(d.size()%2 == 0){
    

    for(int i = d.size() - 1;i >= 1; i = i - 2){
      cout << d[i] << " ";
    }
    for(int i = 0; i <= d.size() - 2;i = i + 2){
      cout << d[i] << " ";
    }
  }
  if(d.size()%2 == 1){
    if(d.size() == 1){
      cout << d[0];
    }
    else{
      for(int i = d.size() - 1;i >= 0; i = i - 2){
	cout << d[i] << " ";
      }
      for(int i = 1; i <= d.size() - 2;i = i + 2){
	cout << d[i] << " ";
      }
    }
  }

}