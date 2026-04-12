# -*- coding: utf-8 -*-
n = int(input())
h = list(map(int, input().split()))
print(len([i for i, x in enumerate(h) if (i == 0) or ((i == 1) and (h[0] <= h[i])) or ((i > 1) and (max(h[:i]) <= h[i]))]))
