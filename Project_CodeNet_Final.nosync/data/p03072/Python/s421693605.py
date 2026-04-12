# python 3.4.3
import sys
input = sys.stdin.readline
import numpy as np

# -------------------------------------------------------------
# function
# -------------------------------------------------------------


# -------------------------------------------------------------
# main
# -------------------------------------------------------------
N = int(input())
H = list(map(int,input().split()))

ans = 0
highest = 0

for h in H:
    if h >= highest:
        ans += 1
        highest = h

print(ans)