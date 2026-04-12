import itertools
import math
import fractions
import functools
import copy

n = int(input())
h = list(map(int, input().split()))

count = 0
maximum = 0
for i in range(n):
    maximum = max(maximum,h[i])
    if maximum <= h[i]:
        count += 1
print(count)