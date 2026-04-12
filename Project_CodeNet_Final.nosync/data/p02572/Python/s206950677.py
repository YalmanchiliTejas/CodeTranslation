N = int(input())
A = list(map(int, input().split()))
mod = 10 ** 9 + 7
sum_a = 0
for a in A:
    a = a % mod
    sum_a = (sum_a + a) % mod
ans = 0
for a in A:
    sum_a = (sum_a - a) % mod
    ans += (a % mod) * sum_a
    ans = ans % mod
print(ans % mod)