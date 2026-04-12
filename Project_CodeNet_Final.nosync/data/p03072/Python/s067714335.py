import itertools
import math

n = int(input())
h = list(map(int, input().split()))

max = 0
count = 0
for i in range(n):
    if h[i] >= max:
        max = h[i]
        count += 1

print(count)