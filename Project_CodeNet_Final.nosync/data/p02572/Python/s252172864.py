import sys
input = sys.stdin.readline

N = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7
ans = 0
s = 0
for a in A:
    ans = (ans + s * a) % mod
    s = (s + a) % mod
print(ans)