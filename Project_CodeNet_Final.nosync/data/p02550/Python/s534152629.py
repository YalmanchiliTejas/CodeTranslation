import sys, math, re
from functools import lru_cache
from collections import deque
sys.setrecursionlimit(10**9)
MOD = 10**9+7

def input():
    return sys.stdin.readline()[:-1]

def mi():
    return map(int, input().split())

def ii():
    return int(input())

def i2(n):
    tmp = [list(mi()) for i in range(n)]
    return [list(i) for i in zip(*tmp)]

def main():
    N, X, M = mi()
    r = [-1]*M

    now = X
    cnt = 0
    while True:
        if r[now] != -1:
            break
            
        r[now] = cnt

        now = (now*now)%M
        cnt += 1
    
    d = [(r[i], i) for i in range(M) if r[i] != -1]
    d.sort()

    s = [v for k, v in d[:r[now]]]
    t = [v for k, v in d[r[now]:]]

    ns = len(s)
    nt = len(t)

    if N < ns:
        print(sum(s[:N]))
        return
    
    print(sum(s) + sum(t) * ((N-ns)//nt) + sum(t[:(N-ns)%nt]))



if __name__ == "__main__":
    main()