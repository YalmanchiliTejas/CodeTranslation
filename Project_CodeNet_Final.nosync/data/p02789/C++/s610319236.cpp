#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef priority_queue<int> pqi;
typedef priority_queue<ll> pqll;
typedef priority_queue<vi> pqvi;
typedef priority_queue<vll> pqvll;
typedef priority_queue<int, vi, greater<int>> pqi_G;
typedef priority_queue<ll, vll, greater<ll>> pqll_G;
typedef priority_queue<vi, vvi, greater<vi>> pqvi_G;
typedef priority_queue<vll, vvll, greater<vll>> pqvll_G;

string ALP = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
string alp = "abcdefghijklmnopqrstuvwxyz";
void Yes() {cout << "Yes" << endl;}
void No() {cout << "No" << endl;}
void YES() {cout << "YES" << endl;}
void NO() {cout << "NO" << endl;}
void neg() {cout << -1 << endl;}

int main() {
  int n, m;
  cin >> n >> m;
  if (n == m) Yes();
  else No();
}