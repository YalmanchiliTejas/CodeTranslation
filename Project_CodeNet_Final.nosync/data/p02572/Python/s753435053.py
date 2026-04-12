# -*- coding: utf-8 -*-
n = int(input())
a = list(map(int, input().split()))

mod = 10 ** 9 + 7

a.reverse()
cumsum = a[0]
sp = 0

for i in a[1:]:
    sp += (cumsum * i) % mod
    sp %= mod

    cumsum += i
    cumsum %= mod

print(sp)
