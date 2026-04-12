#!/usr/bin/env python3

N = int(input().split()[0])
a_list = list(map(int, input().split()))

mod = 10 ** 9 + 7
sum_a = sum(a_list)
total = 0
for i, a in enumerate(a_list):
    total += (a * (sum_a - a)) % mod
    sum_a -= a
total = total % mod
ans = total
print(ans)
