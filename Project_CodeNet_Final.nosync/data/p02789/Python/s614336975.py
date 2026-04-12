def iln(): return list(map(int, input().split()))


def solve(N, M):
  print("Yes" if N == M else "No")
  
  
N, M = iln()
solve(N, M)