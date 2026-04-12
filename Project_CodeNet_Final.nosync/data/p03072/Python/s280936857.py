# -*- coding: utf-8 -*-

N = int(input())
H = list(map(int, input().split()))

ans = sum([1 for i in range(N) if max(H[0:i + 1]) == H[i]])
print(ans)
