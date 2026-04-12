#include <algorithm>
#include <cstdio>
#include <cstdlib>

using namespace std;

#define MAX_NUM_NODES 10

bool is_connected[MAX_NUM_NODES][MAX_NUM_NODES];
int candidate[MAX_NUM_NODES];

void init_candidate(size_t size)
{
  for(size_t i = 0; i < size; i++) {
    candidate[i] = i;
  }
}

int try_candidate(size_t size)
{
  if(size == 0) {
    fputs("size is zero\n", stderr);
    exit(1);
  }
  for(size_t i = 0; i < size-1; i++) {
    if(!is_connected[candidate[i]][candidate[i+1]]) {
      return 0;
    }
  }
  return 1;
}

void init_is_connected()
{
  for(int i = 0; i < MAX_NUM_NODES; i++) {
    for(int j = 0; j < MAX_NUM_NODES; j++) {
      is_connected[i][j] = false;
    }
  }
}

int main()
{
  int num_node, num_edge;
  scanf("%d%d", &num_node, &num_edge);
  for(int i = 0; i < num_edge; i++) {
    int a, b;
    scanf("%d%d", &a, &b);
    is_connected[a-1][b-1] = true;
    is_connected[b-1][a-1] = true;
  }
  init_candidate(num_node);
  long long cnt = 0;
  do {
    cnt += try_candidate(num_node);
  } while(next_permutation(candidate+1, candidate + num_node));
  printf("%lld\n", cnt);
  return 0;
}
