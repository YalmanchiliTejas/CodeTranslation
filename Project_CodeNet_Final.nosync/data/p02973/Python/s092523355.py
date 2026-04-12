import bisect
import sys
input = sys.stdin.readline


n = int(input())
A = [int(input()) for _ in range(n)]
A = A[::-1]
color = [10**10]

for a in A:
    idx = bisect.bisect_right(color, a)
    if idx < len(color):
        color[idx] = a
    else:
        color.append(a)

print(len(color))
