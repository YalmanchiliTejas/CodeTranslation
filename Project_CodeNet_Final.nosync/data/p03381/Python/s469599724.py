# -*- coding: utf-8 -*-


n = int(input())
X = [int(x) for x in input().split()]
X_sorted = sorted(X)

med_l = X_sorted[n // 2 - 1]
med_u = X_sorted[n // 2]
med = (med_l + med_u) / 2

for x in X:
    if x < med:
        print(med_u)
    else:
        print(med_l)
