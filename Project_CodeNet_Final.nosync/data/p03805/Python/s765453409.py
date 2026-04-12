import itertools
from sys import stdin
input = stdin.readline


def main():
  N, M = list(map(int, input().split()))
  map_ = [[0]*(N+1) for _ in range(N+1)]
  for i in range(M):
    a, b = list(map(int, input().split()))
    map_[a][b] = 1
    map_[b][a] = 1

  def is_one_stroke(path):
    now = 1
    for i in range(len(path)):
      next_ = path[i]
      if not map_[now][next_]:
        return False
      now = next_
    return True

  perms = itertools.permutations(list(range(2, N+1)))
  num_path = 0
  for path in perms:
    if (is_one_stroke(path)):
      num_path += 1
  print(num_path)


if(__name__ == '__main__'):
  main()