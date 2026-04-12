MOD = 10**9 + 7 
N = int(input())
A = [int(x) for x in input().split()]
S = sum(A)
ans = 0
for a in A:
    S -= a
    ans = (ans + a * S) % MOD
print(ans)
