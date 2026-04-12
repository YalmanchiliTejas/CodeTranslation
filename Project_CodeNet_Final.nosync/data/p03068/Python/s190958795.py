import sys, math
from collections import deque
sys.setrecursionlimit(500000)
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
    S = input()
    K = ii()
    ans = ''.join([S[i] if S[i] == S[K-1] else '*' for i in range(N)])
    print(ans)


if __name__ == '__main__':
    main()