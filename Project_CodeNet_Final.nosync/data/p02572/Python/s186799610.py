import sys, math
from functools import lru_cache
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
    N = ii()
    A = list(mi())

    s = 0
    t = 0
    for i in range(N):
        s += A[i]*A[i]
        t += A[i]

    print(((t*t-s)//2)%MOD)

if __name__ == '__main__':
    main()
