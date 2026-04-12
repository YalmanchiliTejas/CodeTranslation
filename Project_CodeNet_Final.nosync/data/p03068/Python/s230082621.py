from sys import stdin
# import math
import numpy as np
# N = int(stdin.readline().rstrip().split()[0])
# A = [int(x) for x in stdin.readline().rstrip().split()]
# N, X = [int(x) for x in stdin.readline().rstrip().split()]
# S = stdin.readline().rstrip().split()[0]

N = int(stdin.readline().rstrip().split()[0])
S = stdin.readline().rstrip().split()[0]
K = int(stdin.readline().rstrip().split()[0])

K = K-1

S_k = S[K]
arr = ""
for s in S:
  if s==S_k:
    arr += s
  else:
    arr += "*"
print(arr)

