import math
import sys
import os
from operator import mul
import numpy as np

sys.setrecursionlimit(10**7)

def _S(): return sys.stdin.readline().rstrip()
def I(): return int(_S())
def LS(): return list(_S().split())
def LI(): return list(map(int,LS()))

if os.getenv("LOCAL"):
    inputFile = basename_without_ext = os.path.splitext(os.path.basename(__file__))[0]+'.txt'
    sys.stdin = open(inputFile, "r")
INF = float("inf")

MOD = 10 ** 9 + 7

N = I()
A = LI()
ans = 0

# A = np.array(A)
sum = [0]*(N+1)
for i in range(N):
        sum[i+1] = sum[i]+A[i]

for i in range(N-1):
    ans += A[i] * (sum[N] - sum[i+1]) % MOD

       
print(ans%MOD)