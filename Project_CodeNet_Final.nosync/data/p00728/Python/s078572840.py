#-*- encoding:utf-8 -*-
import math

while 1:
    n = int(input())
    if n == 0:
        break
    max = 0
    min = 9999
    sum = 0
    for i in range(n):
        s = int(input())
        if max < s:
            max = s
        if min > s:
            min = s
        sum = sum + s
    ans = math.floor((sum - min - max) / (n-2))
    print(ans)