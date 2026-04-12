import sys
INF = 1 << 60
MOD = 10**9 + 7 # 998244353
sys.setrecursionlimit(2147483647)
input = lambda:sys.stdin.readline().rstrip()
def resolve():
    n = int(input())
    A = list(map(int, input().split()))
    s = sum(A)
    t = sum(a * a for a in A)
    print((s ** 2 - t) * pow(2, MOD - 2, MOD) % MOD)
resolve()