N = int(input())
A = list(map(int, input().split()))

mod = 10**9 + 7
sum_modA = 0
for a in A:
    sum_modA = (sum_modA + a) % mod

sum_mul = sum_modA**2 % mod
for a in A:
    sum_mul = (sum_mul - a**2 % mod) % mod

sum_mul = sum_mul * pow(2, mod - 2, mod) % mod

print(sum_mul)