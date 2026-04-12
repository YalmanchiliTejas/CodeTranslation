#define debug(x) cout<<#x<<": "<<x<<endl
#define rep(a, b) for(int unsafe_cnt=a; unsafe_cnt < b;unsafe_cnt++)
#define fn auto
#include <iostream>
#include <stdio.h>
#include <vector>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

void newline() {cout << endl;}
template <typename T> void display(T input){cout << input;}
template <typename T> void put(T input){display(input); newline();}
void iput(int input) {put(input);}

fn main() -> int {
  int a, b, c;
  cin >> a >> b >> c;
  cout << ((100*a + 10*b + c) % 4 == 0  ? "YES" : "NO")  << endl;
}