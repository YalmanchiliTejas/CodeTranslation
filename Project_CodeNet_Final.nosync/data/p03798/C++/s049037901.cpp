#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <iomanip>
#include <stack>
#include <queue>
#include <numeric>
#include <map>
#include <unordered_map>
#include <set>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define pb push_back
#define mod 1000000007
using ll = long long;
using namespace std;

int left(int x, int n){
  return (x+1)%n;
}

int right(int x, int n){
  return (x-1+n)%n;
}

int main(){
  int N; cin >> N;
  string s; cin >> s;
  vector<char> animals(N,'N');
  // s[0] is sheep, s[1] is sheep
  animals[0] = animals[1] = 'S';
  rep(i,N){
    if(animals[i] == 'S'){
      if(s[i] == 'o'){
        if(animals[left(i,N)] == 'N'){
          animals[left(i,N)] = animals[right(i,N)];
        }
        if(animals[right(i,N)] == 'N'){
          animals[right(i,N)] = animals[left(i,N)];
        }
        if(animals[left(i,N)] != animals[right(i,N)]){
          break;
        }
      }
      if(s[i] == 'x'){
        if(animals[left(i,N)] == 'N'){
          if(animals[right(i,N)] == 'S'){
            animals[left(i,N)] = 'W';
          }
          else{
            animals[left(i,N)] = 'S';
          }
        }
        if(animals[right(i,N)] == 'N'){
          if(animals[left(i,N)] == 'S'){
            animals[right(i,N)] = 'W';
          }
          else{
            animals[right(i,N)] = 'S';
          }
        }
        if(animals[left(i,N)] == animals[right(i,N)]){
          break;
        }
      }
    }
    if(animals[i] == 'W'){
      if(s[i] != 'o'){
        if(animals[left(i,N)] == 'N'){
          animals[left(i,N)] = animals[right(i,N)];
        }
        if(animals[right(i,N)] == 'N'){
          animals[right(i,N)] = animals[left(i,N)];
        }
        if(animals[left(i,N)] != animals[right(i,N)]){
          break;
        }
      }
      if(s[i] != 'x'){
        if(animals[left(i,N)] == 'N'){
          if(animals[right(i,N)] == 'S'){
            animals[left(i,N)] = 'W';
          }
          else{
            animals[left(i,N)] = 'S';
          }
        }
        if(animals[right(i,N)] == 'N'){
          if(animals[left(i,N)] == 'S'){
            animals[right(i,N)] = 'W';
          }
          else{
            animals[right(i,N)] = 'S';
          }
        }
        if(animals[left(i,N)] == animals[right(i,N)]){
          break;
        }
      }
    }
    if(i==N-1){
      rep(i,N) cout << animals[i];
      cout << endl;
      return 0;
    }
  }
  // s[0] is sheep, s[1] is wolf
  rep(i,N) animals[i] = 'N';
  animals[0] = 'S';
  animals[1] = 'W';
  rep(i,N){
    if(animals[i] == 'S'){
      if(s[i] == 'o'){
        if(animals[left(i,N)] == 'N'){
          animals[left(i,N)] = animals[right(i,N)];
        }
        if(animals[right(i,N)] == 'N'){
          animals[right(i,N)] = animals[left(i,N)];
        }
        if(animals[left(i,N)] != animals[right(i,N)]){
          break;
        }
      }
      if(s[i] == 'x'){
        if(animals[left(i,N)] == 'N'){
          if(animals[right(i,N)] == 'S'){
            animals[left(i,N)] = 'W';
          }
          else{
            animals[left(i,N)] = 'S';
          }
        }
        if(animals[right(i,N)] == 'N'){
          if(animals[left(i,N)] == 'S'){
            animals[right(i,N)] = 'W';
          }
          else{
            animals[right(i,N)] = 'S';
          }
        }
        if(animals[left(i,N)] == animals[right(i,N)]){
          break;
        }
      }
    }
    if(animals[i] == 'W'){
      if(s[i] != 'o'){
        if(animals[left(i,N)] == 'N'){
          animals[left(i,N)] = animals[right(i,N)];
        }
        if(animals[right(i,N)] == 'N'){
          animals[right(i,N)] = animals[left(i,N)];
        }
        if(animals[left(i,N)] != animals[right(i,N)]){
          break;
        }
      }
      if(s[i] != 'x'){
        if(animals[left(i,N)] == 'N'){
          if(animals[right(i,N)] == 'S'){
            animals[left(i,N)] = 'W';
          }
          else{
            animals[left(i,N)] = 'S';
          }
        }
        if(animals[right(i,N)] == 'N'){
          if(animals[left(i,N)] == 'S'){
            animals[right(i,N)] = 'W';
          }
          else{
            animals[right(i,N)] = 'S';
          }
        }
        if(animals[left(i,N)] == animals[right(i,N)]){
          break;
        }
      }
    }
    if(i==N-1){
      rep(i,N) cout << animals[i];
      cout << endl;
      return 0;
    }
  }
  // s[0] is wolf,  s[1] is sheep
  rep(i,N) animals[i] = 'N';
  animals[0] = 'W';
  animals[1] = 'S';
  rep(i,N){
    if(animals[i] == 'S'){
      if(s[i] == 'o'){
        if(animals[left(i,N)] == 'N'){
          animals[left(i,N)] = animals[right(i,N)];
        }
        if(animals[right(i,N)] == 'N'){
          animals[right(i,N)] = animals[left(i,N)];
        }
        if(animals[left(i,N)] != animals[right(i,N)]){
          break;
        }
      }
      if(s[i] == 'x'){
        if(animals[left(i,N)] == 'N'){
          if(animals[right(i,N)] == 'S'){
            animals[left(i,N)] = 'W';
          }
          else{
            animals[left(i,N)] = 'S';
          }
        }
        if(animals[right(i,N)] == 'N'){
          if(animals[left(i,N)] == 'S'){
            animals[right(i,N)] = 'W';
          }
          else{
            animals[right(i,N)] = 'S';
          }
        }
        if(animals[left(i,N)] == animals[right(i,N)]){
          break;
        }
      }
    }
    if(animals[i] == 'W'){
      if(s[i] != 'o'){
        if(animals[left(i,N)] == 'N'){
          animals[left(i,N)] = animals[right(i,N)];
        }
        if(animals[right(i,N)] == 'N'){
          animals[right(i,N)] = animals[left(i,N)];
        }
        if(animals[left(i,N)] != animals[right(i,N)]){
          break;
        }
      }
      if(s[i] != 'x'){
        if(animals[left(i,N)] == 'N'){
          if(animals[right(i,N)] == 'S'){
            animals[left(i,N)] = 'W';
          }
          else{
            animals[left(i,N)] = 'S';
          }
        }
        if(animals[right(i,N)] == 'N'){
          if(animals[left(i,N)] == 'S'){
            animals[right(i,N)] = 'W';
          }
          else{
            animals[right(i,N)] = 'S';
          }
        }
        if(animals[left(i,N)] == animals[right(i,N)]){
          break;
        }
      }
    }
    if(i==N-1){
      rep(i,N) cout << animals[i];
      cout << endl;
      return 0;
    }
  }
  // s[0] is wolf,  s[1] is wolf
  rep(i,N) animals[i] = 'N';
  animals[0] = 'W';
  animals[1] = 'W';
  rep(i,N){
    if(animals[i] == 'S'){
      if(s[i] == 'o'){
        if(animals[left(i,N)] == 'N'){
          animals[left(i,N)] = animals[right(i,N)];
        }
        if(animals[right(i,N)] == 'N'){
          animals[right(i,N)] = animals[left(i,N)];
        }
        if(animals[left(i,N)] != animals[right(i,N)]){
          break;
        }
      }
      if(s[i] == 'x'){
        if(animals[left(i,N)] == 'N'){
          if(animals[right(i,N)] == 'S'){
            animals[left(i,N)] = 'W';
          }
          else{
            animals[left(i,N)] = 'S';
          }
        }
        if(animals[right(i,N)] == 'N'){
          if(animals[left(i,N)] == 'S'){
            animals[right(i,N)] = 'W';
          }
          else{
            animals[right(i,N)] = 'S';
          }
        }
        if(animals[left(i,N)] == animals[right(i,N)]){
          break;
        }
      }
    }
    if(animals[i] == 'W'){
      if(s[i] != 'o'){
        if(animals[left(i,N)] == 'N'){
          animals[left(i,N)] = animals[right(i,N)];
        }
        if(animals[right(i,N)] == 'N'){
          animals[right(i,N)] = animals[left(i,N)];
        }
        if(animals[left(i,N)] != animals[right(i,N)]){
          break;
        }
      }
      if(s[i] != 'x'){
        if(animals[left(i,N)] == 'N'){
          if(animals[right(i,N)] == 'S'){
            animals[left(i,N)] = 'W';
          }
          else{
            animals[left(i,N)] = 'S';
          }
        }
        if(animals[right(i,N)] == 'N'){
          if(animals[left(i,N)] == 'S'){
            animals[right(i,N)] = 'W';
          }
          else{
            animals[right(i,N)] = 'S';
          }
        }
        if(animals[left(i,N)] == animals[right(i,N)]){
          break;
        }
      }
    }
    if(i==N-1){
      rep(i,N) cout << animals[i];
      cout << endl;
      return 0;
    }
  }

  // else
  cout << -1 << endl;
  return 0;
}
