inpl = lambda: list(map(int,input().split()))
MOD = 10**9+7
N = int(input())
A = inpl()
S = sum(A) % MOD
T = sum(a*a % MOD for a in A) % MOD
U = S*S - T
if U % 2:
    U += MOD
ans = (U//2) % MOD

print(ans)
