import sys
input = sys.stdin.readline
# 二分木
import bisect

n = int(input())
a = []

for _ in range(n):
    ai = int(input()) * -1
    i = bisect.bisect_right(a,ai)
    if(i==len(a)):
        a.append(ai)
    else:
        a[i] = ai

print(len(a))