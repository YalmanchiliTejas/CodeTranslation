import numpy as np
import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
sys.setrecursionlimit(10**8)
INF = float('inf')
MOD = 10**9+7


def main():
  N = int(readline())
  H = list(map(int, readline().split()))
  max_h = 0
  ans = 0
  for i in range(N):
    h = H[i]
    if max(h,max_h) == h:
      max_h = h
      ans += 1
  print(ans)
  
  
  
if __name__ == '__main__':
  main()