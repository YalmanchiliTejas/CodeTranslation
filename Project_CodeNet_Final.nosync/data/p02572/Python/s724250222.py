n = int(input())
a = list(map(int, input().split()))

answer = 0
mod = 10**9 + 7
total_sum = sum(a)
for idx in range(n - 1):
    total_sum -= a[idx]
    answer += a[idx] * total_sum

print(answer % mod)