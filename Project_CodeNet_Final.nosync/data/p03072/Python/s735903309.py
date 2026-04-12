import numpy as np
n=int(input())  #数値入力
h=list(map(int, input().split()))  #リスト入力
count = 0
high = h[0]
for i in range(n):
    if h[i] >= high:
        count += 1
        high = h[i]

print(count)