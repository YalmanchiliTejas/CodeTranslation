# 177 C
N = int(input())
A = list(map(int, input().split()))
mod = 10**9 + 7

sq_sum = sum(map(lambda x: x*x, A))
sum_sq = sum(A) * sum(A)
answer = (sum_sq - sq_sum) // 2

print(answer % mod)