import sys
sys.setrecursionlimit(10**6)

n = int(input())
A = list(map(int, input().split()))
#n, m = map(int, input().split())
#s = input()
#s,t = input().split()
#a = [int(input()) for _ in range(n)]
#
#readline = sys.stdin.readline
#n,m = [int(i) for i in readline().split()]
#ab = [[int(i) for i in readline().split()] for _ in range(n)]

MOD = 10**9+7

tot = sum(A)
tot %= MOD

ans = 0
rmv = 0

for a in A:
    rmv += a
    rmv %= MOD
    ans += a*(tot-rmv)
    ans %= MOD

print(ans)
