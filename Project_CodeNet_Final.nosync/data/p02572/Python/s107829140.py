N = int(input())
A = list(map(int, input().split()))
A_sum = sum(A)
MOD = 10**9 + 7
ans = 0
A_cum = 0
for a in A:
    A_cum += a
    ans += a  * (A_sum - A_cum) % MOD
print(ans % MOD)