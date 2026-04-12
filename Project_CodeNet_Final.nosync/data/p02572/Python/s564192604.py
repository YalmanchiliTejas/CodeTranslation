N = int(input())
A = list(map(int, input().split()))

sum_A = sum(A)

mod = 10**9 + 7

sum_mod = 0

sum_minus = 0
for a in A:
    sum_mod += a * (sum_A - a - sum_minus) % mod
    sum_minus += a

print(sum_mod % mod)