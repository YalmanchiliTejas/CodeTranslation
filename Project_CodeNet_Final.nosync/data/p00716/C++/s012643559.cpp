#include <cstdio>
#include <iostream>

using namespace std;

int solve(int a, int year, int t, double r, int q)
{
  int b, x;
  int y = 0;

  if(t == 1){
    for(int i = 0; i < year; i++){
      b = a * r;
      x = a + b - q;
      a = x;
    }
  }

  if(t == 0){
    for(int i = 0; i < year; i++){
      b = a * r;
      x = a - q;
      y += b;
      a = x;
    }
  }

  return x + y;
}

int main()
{
  int m, a, year, n, t, q;
  double r;
  int d[110];
  cin >> m;
  for(int i = 0; i < m; i++){
    cin >> a;
    cin >> year;
    cin >> n;
    for(int i = 0; i < n; i++){
      scanf("%d %lf %d", &t, &r, &q);
      d[i] = solve(a, year, t, r, q);
    }
    int max = 0;
    for(int i = 0; i < n; i++){
      if(max < d[i]) max = d[i];
    }
    cout << max << endl;
  }

  return 0;
}