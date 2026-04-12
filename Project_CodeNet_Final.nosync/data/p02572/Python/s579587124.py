import sys
input = sys.stdin.readline
N = int(input())
A = map(int, input().split())
S = 0
S2 = 0
M = 10**9+7
for a in A:
  S += a
  S %= M
  S2 += a*a
  S2 %= M

# (S * S - S2)/2 
ans = (S * S - S2) * pow(2, -1, M)
ans %= M
print(ans)