N = int(input())
A = list(map(int, input().split()))


sum_a = sum(A)
ans = 0
mod = int(1e9+7)

for a in A:
    sum_a -= a
    ans += (sum_a * a)

ans %= 1000000007

print(int(ans))
