from functools import reduce
from fractions import gcd
import math
import bisect
import itertools
import sys
input = sys.stdin.readline
INF = float("inf")


def func(x, m):
    return x % m


# 処理内容
def main():
    N, X, M = map(int, input().split())

    L = [-1]*M
    route = []
    ans = 0
    a = 0
    l = 0
    r = N
    for i in range(N):
        if i == 0:
            a = X
        else:
            a = func(a**2, M)
        if L[a] >= 0:
            if N:
                pass
            l = L[a]
            r = i
            break
        else:
            L[a] = i
            route.append(a)
    
    ans += sum(route[:l])
    k = (N - l) // (r - l)
    m = (N - l) % (r - l)
    ans += sum(route[l:]) * k
    ans += sum(route[l:l+m])
    
    print(ans)



if __name__ == '__main__':
    main()