#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
  for(int tci = 0; ; tci++) {
    int H,W,C,M,NW,NC,NM; scanf("%d%d%d%d%d%d%d", &H, &W, &C, &M, &NW, &NC, &NM);
    if(H<0) break;
#define START 0
#define V_H(x)   (1+(x))
#define V_W(x)   (1+H+(x))
#define V_W2(x)  (1+H+W+(x))
#define V_NW(x)  (1+H+W+W+(x))
#define V_NW2(x) (1+H+W+W+NW+(x))
#define V_C(x)   (1+H+W+W+NW+NW+(x))
#define V_C2(x)  (1+H+W+W+NW+NW+C+(x))
#define V_NC(x)  (1+H+W+W+NW+NW+C+C+(x))
#define V_NC2(x) (1+H+W+W+NW+NW+C+C+NC+(x))
#define V_M(x)   (1+H+W+W+NW+NW+C+C+NC+NC+(x))
#define V_NM(x)  (1+H+W+W+NW+NW+C+C+NC+NC+M+(x))
#define TERMINAL (1+H+W+W+NW+NW+C+C+NC+NC+M+NM)
#define SIZE     (1+H+W+W+NW+NW+C+C+NC+NC+M+NM+1)

    vector<vector<int> > capa(SIZE, vector<int>(SIZE, 0));
    for(int i = 0; i < H; i++) {
      capa[START][V_H(i)] = 1;
    }
    for(int i = 0; i < W; i++) {
      int n; scanf("%d", &n);
      for(int j = 0; j < n; j++) {
        int k; scanf("%d", &k); k--;
        capa[V_H(k)][V_W(i)] = 1;
      }
    }
    for(int i = 0; i < NW; i++) {
      for(int j = 0; j < H; j++) {
        capa[V_H(j)][V_NW(i)] = 1;
      }
    }
    for(int i = 0; i < W; i++) {
      capa[V_W(i)][V_W2(i)] = 1;
    }
    for(int i = 0; i < NW; i++) {
      capa[V_NW(i)][V_NW2(i)] = 1;
    }
    for(int i = 0; i < C; i++) {
      int n; scanf("%d", &n);
      for(int j = 0; j < n; j++) {
        int k; scanf("%d", &k); k--;
        capa[V_W2(k)][V_C(i)] = 1;
      }
      for(int j = 0; j < NW; j++) {
        capa[V_NW2(j)][V_C(i)] = 1;
      }
    }
    for(int i = 0; i < NC; i++) {
      for(int j = 0; j < W; j++) {
        capa[V_W2(j)][V_NC(i)] = 1;
      }
    }
    for(int i = 0; i < C; i++) {
      capa[V_C(i)][V_C2(i)] = 1;
    }
    for(int i = 0; i < NC; i++) {
      capa[V_NC(i)][V_NC2(i)] = 1;
    }
    for(int i = 0; i < M; i++) {
      int n; scanf("%d", &n);
      for(int j = 0; j < n; j++) {
        int k; scanf("%d", &k); k--;
        capa[V_C2(k)][V_M(i)] = 1;
      }
      for(int j = 0; j < NC; j++) {
        capa[V_NC2(j)][V_M(i)] = 1;
      }
    }
    for(int i = 0; i < NM; i++) {
      for(int j = 0; j < C; j++) {
        capa[V_C2(j)][V_NM(i)] = 1;
      }
    }
    for(int i = 0; i < M; i++) {
      capa[V_M(i)][TERMINAL] = 1;
    }
    for(int i = 0; i < NM; i++) {
      capa[V_NM(i)][TERMINAL] = 1;
    }
    int flow = 0;
    while(true) {
      vector<int> par(SIZE, -1);
      vector<int> stk; stk.reserve(SIZE);
      stk.push_back(START);
      par[START] = -2;
      while(!stk.empty()) {
        int v = stk.back(); stk.pop_back();
        if(v == TERMINAL) {
          for(int w = v; w != START; w=par[w]) {
            capa[par[w]][w]--;
            capa[w][par[w]]++;
          }
          flow++;
          goto cont;
        }
        for(int w = 0; w < SIZE; w++) {
          if(capa[v][w] == 1 && par[w]==-1) {
            par[w]=v;
            stk.push_back(w);
          }
        }
      }
      break;
cont:continue;
    }
    printf("%d\n", flow);
  }
  return 0;
}