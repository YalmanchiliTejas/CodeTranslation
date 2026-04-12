n = int(input())
a = list(map(int, input().split()))
mod = 10**9+7

sq_sum_a = sum(a)**2
sum_sq_a = sum(map(lambda x: x**2, a))

sum_cross = (sq_sum_a - sum_sq_a) // 2
ans = sum_cross % mod

print(ans)