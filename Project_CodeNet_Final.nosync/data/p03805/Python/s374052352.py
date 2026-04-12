from collections import deque
from collections import Counter
from itertools import product, permutations,combinations
import sys
input = sys.stdin.readline
#文字列のときはうまく行かないのでコメントアウトすること
sys.setrecursionlimit(2147483647)

def main():
  n, m = map(int, input().split())
  #隣接リストを作る
  path = [[False for i in range(n)] for j in range(n)]
  for i in range(m):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    path[a][b] = True
    path[b][a] = True
  ans = 0
  for i in permutations(range(n), n):
    if i[0] == 0:
      for j in range(n):
        if j == n-1:
          ans += 1
          break
        if not path[i[j]][i[j+1]]:
          break
  print(ans)

if __name__ == '__main__':
  main()