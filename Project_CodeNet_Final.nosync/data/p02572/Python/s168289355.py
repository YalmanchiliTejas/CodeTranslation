N = int(input())
A = list(map(int, input().split()))

mod = 10**9+7

sums = []
current_sum = 0
for a in A[1:][::-1]:
    current_sum += a
    sums.append(current_sum)
sums = sums[::-1]

ans = 0
for a, b in zip(A[:-1], sums):
    ans += a * b
    ans = ans % mod

print(ans)