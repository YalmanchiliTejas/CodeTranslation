MOD = 10**9 + 7

N = int(input())
A = list(map(int, input().split()))

sum_sq = pow(sum(A), 2)
sq_sum = sum([a**2 for a in A])

ans = (sum_sq - sq_sum) // 2 % MOD
print(ans)