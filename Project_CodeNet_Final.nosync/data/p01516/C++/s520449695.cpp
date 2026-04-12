#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1);
const double INF = 100000;
const double EPS = 1e-8;
int sign(double x){
  if (x > EPS){
    return 1;
  } else if (x < - EPS){
    return -1;
  } else {
    return 0;
  }
}
struct point{
  double x, y;
  point(){
  }
  point(double x, double y): x(x), y(y){
  }
  point operator +(point P){
    return point(x + P.x, y + P.y);
  }
  point operator -(point P){
    return point(x - P.x, y - P.y);
  }
  point operator *(double k){
    return point(x * k, y * k);
  }
  point operator /(double k){
    return point(x / k, y / k);
  }
};
double abs(point P){
  return sqrt(pow(P.x, 2) + pow(P.y, 2));
}
double distance(point P, point Q){
  return abs(Q - P);
}
double dot(point P, point Q){
  return P.x * Q.x + P.y * Q.y;
}
double cross(point P, point Q){
  return P.x * Q.y - P.y * Q.x;
}
struct line{
  point A, B;
  line(){
  }
  line(point A, point B): A(A), B(B){
  }
};
point vec(line L){
  return L.B - L.A;
}
bool is_parallel(line L1, line L2){
  return sign(cross(vec(L1), vec(L2))) == 0;
}
bool on_segment(point P, line L){
  return sign(dot(P - L.A, vec(L))) == 1 && sign(dot(P - L.B, vec(L))) == -1;
}
point line_intersection(line L1, line L2){
  return L1.A + vec(L1) * cross(L2.A - L1.A, vec(L2)) / cross(vec(L1), vec(L2));
}
bool segment_intersection(line L1, line L2){
  point P = line_intersection(L1, L2);
  return on_segment(P, L1) && on_segment(P, L2);
}
double point_line_distance(point P, line L){
  return abs(cross(P - L.A, vec(L))) / abs(vec(L));
}
double point_segment_distance(point P, line L){
  if (dot(vec(L), P - L.A) < 0){
    return distance(P, L.A);
  } else if (dot(vec(L), P - L.B) > 0){
    return distance(P, L.B);
  } else {
    return point_line_distance(P, L);
  }
}
struct star{
  array<line, 5> L;
  star(){
  }
  star(double x, double y, double a, double r){
    array<point, 6> P;
    for (int i = 0; i < 6; i++){
      double theta = a + PI * 4 / 5 * i;
      P[i] = point(x - r * sin(theta), y + r * cos(theta));
    }
    for (int i = 0; i < 5; i++){
      L[i] = line(P[i], P[i + 1]);
    }
  }
  line operator [](int k){
    return L[k];
  }
};
double star_distance(star S1, star S2){
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      if (!is_parallel(S1[i], S2[j])){
        if (segment_intersection(S1[i], S2[j])){
          return 0;
        }
      }
    }
  }
  double ans = INF;
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      ans = min(ans, point_segment_distance(S1[i].A, S2[j]));
    }
  }
  for (int i = 0; i < 5; i++){
    for (int j = 0; j < 5; j++){
      ans = min(ans, point_segment_distance(S2[i].A, S1[j]));
    }
  }
  return ans;
}
int main(){
  cout << fixed << setprecision(6);
  while (1){
    int N, M, L;
    cin >> N >> M >> L;
    if (N == 0 && M == 0 && L == 0){
      break;
    }
    M--;
    L--;
    vector<star> S(N);
    for (int i = 0; i < N; i++){
      double x, y, a, r;
      cin >> x >> y >> a >> r;
      a = a / 180 * PI;
      S[i] = star(x, y, a, r);
    }
    vector<double> d(N, INF);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<pair<double, int>>> pq;
    pq.push(make_pair(0, M));
    while (!pq.empty()){
      double c = pq.top().first;
      int v = pq.top().second;
      pq.pop();
      if (d[v] == INF){
        d[v] = c;
        for (int i = 0; i < N; i++){
          if (d[i] == INF){
            pq.push(make_pair(c + star_distance(S[v], S[i]), i));
          }
        }
      }
    }
    cout << d[L] << endl;
  }
}
