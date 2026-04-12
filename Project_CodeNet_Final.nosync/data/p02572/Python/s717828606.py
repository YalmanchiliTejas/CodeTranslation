import sys
#import string
#from collections import defaultdict, deque, Counter
#import bisect
#import heapq
#import math
#from itertools import accumulate
#from itertools import permutations as perm
#from itertools import combinations as comb
#from itertools import combinations_with_replacement as combr
#from fractions import gcd
#import numpy as np

stdin = sys.stdin
sys.setrecursionlimit(10 ** 7)
MIN = -10 ** 9
MOD = 10 ** 9 + 7
INF = float("inf")
IINF = 10 ** 18

def solve():
    n = int(stdin.readline().rstrip())
    #A, B, C = map(int, stdin.readline().rstrip().split())
    A = list(map(int, stdin.readline().rstrip().split()))
    #numbers = [[int(c) for c in l.strip().split()] for l in sys.stdin]
    #word = [stdin.readline().rstrip() for _ in range(n)]
    #number = [[int(c) for c in stdin.readline().rstrip()] for _ in range(n)]
    #zeros = [[0] * w for i in range(h)]
    S = [0]
    for i in range(n):
        S.append(S[i]+A[i])
    ans = 0
    for i in range(n-1):
        ans += (( A[i] * (S[-1] - S[i+1])) % MOD)
    print(ans%MOD)

if __name__ == '__main__':
    solve()
