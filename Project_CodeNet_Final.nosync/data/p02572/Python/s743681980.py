
import sys
input = sys.stdin.readline
MOD = 10**9 + 7
N = int(input())
A = list(map(int,input().split()))

S = sum(A) % MOD
T = sum([a*a for a in A]) % MOD

ans = (S*S - T) % MOD
if ans % 2 == 1:
	ans += MOD
print(ans // 2)