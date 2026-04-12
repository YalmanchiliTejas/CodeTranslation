import bisect
import sys
input = sys.stdin.readline

n = int(input())
colors_maxs = []

colors_maxs.append(int(input()) *(-1) )
for _ in range(n-1):
    a = int(input()) * (-1)
    if colors_maxs[-1] <= a:
        colors_maxs.append(a)
    else:
        ind = bisect.bisect_right(colors_maxs, a) # -> 4
        colors_maxs[ind] = a

print(len(colors_maxs))