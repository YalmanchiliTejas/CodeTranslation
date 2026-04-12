import sys
import math
import collections
from collections import deque
from functools import reduce
import heapq
#n = int(input())
a, b, c, x, y = map(int, sys.stdin.readline().split())
#s = input()
#a = list(map(int, sys.stdin.readline().split()))

n = max(x, y)
ans = 10 ** 10
for i in range(n+1):
    p = max(x - i, 0)
    q = max(y - i, 0)
    r = 2 * i * c + p * a + q * b
    if r < ans:
        ans = r

print(ans)
    

        
