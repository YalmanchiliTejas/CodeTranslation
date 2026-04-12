#
import sys
import math
import numpy as np
import itertools


# ひとつ入力
n = int(input())

# リストに入れる
h = [int(i) for i in input().split()] 

highest = 0
answer = 0

for i in range(n):
    if h[i] >= highest:
        answer += 1
        highest = h[i]
    
print(answer)


