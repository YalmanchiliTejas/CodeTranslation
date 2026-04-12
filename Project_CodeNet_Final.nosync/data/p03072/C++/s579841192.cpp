#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


void white_cells()
{
  int H, W, h, w;
  cin >> H >> W >> h >> w;

  cout << (H * W) - (h * W) - (H * w) + (h * w) << "\n";
}


void double_helix()
{
  char b;
  cin >> b;

  if (b == 'A') cout << "T\n";
  else if (b == 'T') cout << "A\n";
  else if (b == 'C') cout << "G\n";
  else  cout << "C\n";

}


void five_antennas()
{
  vector<int> a(5);
  for (int i = 0; i < 5; ++i) cin >> a[i];
  int k;
  cin >> k;

  if (a[4] - a[0] > k)
  {
    cout << ":(\n";
    return;
  }
  cout << "Yay!\n";

}

void buttons()
{
  int a, b;
  cin >> a >> b;

  int v_max = 0;
  for (int i = 0; i < 2; ++i) {
    if (a > b) {
      v_max += a;
      --a;
    }
    else
    {
      v_max += b;
      --b;
    }
  }
  cout << v_max << "\n";
}


void biscuit_generator()
{
  int a, b, t;
  cin >> a >> b >> t;

  cout << t / a * b << "\n";
}


void changing_a_character()
{
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;

  s[k - 1] += 32;
  cout << s <<"\n";
}


void ferris_wheel()
{
  int a, b;
  cin >> a >> b;

  if (a >= 13) cout << b << "\n";
  else if(a >= 6) cout << b / 2 << "\n";
  else cout << 0 << "\n";
}


void apple_pie()
{
  int a, p;
  cin >> a >> p;

  p += 3 * a;

  cout << p / 2 << "\n";
}


void airplane()
{
  vector<int> a(3);
  for (int i = 0; i < 3; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  cout << a[0] + a[1] << "\n";
}


void rounding()
{
  int x, a;
  cin >> x >> a;

  if (x < a) cout << 0 << "\n";
  else cout << 10 << "\n";
}




void can_you_solve_this()
{
  int n, m, c;
  cin >> n >> m >> c;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) cin >> b[i];
  vector<vector<int>> a(n, vector<int>(m));
  for (int i = 0; i < n; ++i) for (int j = 0; j < m; ++j) cin >> a[i][j];

  int cnt = 0;
  for (int i = 0; i < n; ++i)
  {
    int point = 0;
    for (int j = 0; j < m; ++j) point += a[i][j] * b[j];

    if (point > -c) ++cnt;
  }
  cout << cnt << "\n";
} 


void ATCoder()
{
  string s;
  cin >> s;

  int ans = 0;
  for (int i = 0; i < s.size(); ++i)
  {
    int cnt = 0;
    while (i < s.size() && (s[i] == 'A' || s[i] == 'C' || s[i] == 'G' || s[i] == 'T'))
    {
      ++cnt;
      ++i;
    }
    ans = max(ans, cnt);
  }
  cout << ans << "\n";
}


void five_dises()
{
  vector<int> v(5);
  int r_max = 0;
  int ans = 0;
  for (int i = 0; i < 5; ++i)
  {
    cin >> v[i];
    if (v[i] % 10 != 0)
    {
      r_max = max(r_max, 10 - v[i] % 10);
      v[i] += 10 - (v[i] % 10);
    }
    ans += v[i];
  }
  ans -= r_max;
  cout << ans << "\n";
}


void great_ocean_view()
{
  int n;
  cin >> n;
  vector<int> h(n);
  for (int i = 0; i < n; ++i)cin >> h[i];

  int v_max = 0, cnt = 0;
  for (int i = 0; i < n; ++i)
  {
    if (h[i] >= v_max)
    {
      v_max = h[i];
      ++cnt;
    }
  }
  cout << cnt << "\n";
}


void resale()
{
  int n;
  cin >> n;
  vector<int> v(n), c(n);
  for (int i = 0; i < n; ++i) cin >> v[i];
  for (int i = 0; i < n; ++i) cin >> c[i];


}


int main()
{
  //white_cells();
  //double_helix();
  //five_antennas();
  //buttons();
  //biscuit_generator();
  //changing_a_character();
  //ferris_wheel();
  //apple_pie();
  //airplane();
  //rounding();


  //can_you_solve_this();
  //ATCoder();
  //five_dises();
  great_ocean_view();
  //resale();
}