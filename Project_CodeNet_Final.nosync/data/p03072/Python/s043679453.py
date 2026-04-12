from sys import stdin
# import math
import numpy as np
# N = int(stdin.readline().rstrip().split()[0])
# A = [int(x) for x in stdin.readline().rstrip().split()]
# N, X = [int(x) for x in stdin.readline().rstrip().split()]
# S = [int(x) for x in stdin.readline().rstrip().split()]
N = int(stdin.readline().rstrip().split()[0])
H = [int(x) for x in stdin.readline().rstrip().split()]
H = np.array(H)

ans = 0
for i in range(N):
  max_m = H[:i+1].max()
  if max_m==H[i]:
    ans += 1

print(ans)