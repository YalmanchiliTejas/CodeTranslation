from sys import stdin
def solve():
  n,m=map(int,stdin.readline().split())
  if n==m:
    print('Yes')
  else:
    print('No')
solve()