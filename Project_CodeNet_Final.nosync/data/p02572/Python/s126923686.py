import sys
import math
import itertools
import collections
from collections import deque
from collections import defaultdict

sys.setrecursionlimit(1000000)
MOD = 10 ** 9 + 7
MOD2 = 998244353
INF = float('inf')
input = lambda: sys.stdin.readline().strip()
NI = lambda: int(input())
NMI = lambda: map(int, input().split())
NLI = lambda: list(NMI())
SI = lambda: input()

def main():
    N = NI()
    A = NLI()
    
    sum_A = sum(A)
    ans = 0
    
    for n in range(N):
        sum_A -= A[n] 
        ans += (A[n] * sum_A)%MOD
        ans = ans % MOD
    print(ans)
        



if __name__ == '__main__':
    main()