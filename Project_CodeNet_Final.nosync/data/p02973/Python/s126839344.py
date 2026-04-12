import sys
import bisect

n = int(input())
a = [int(sys.stdin.readline().rstrip()) for _ in range(n)][::-1]

bottoms = [a[0]]

for i in range(1, n):
    pos = bisect.bisect_right(bottoms, a[i])
    if pos == len(bottoms):
        bottoms.append(a[i])
    else:
        bottoms[pos] = a[i]

print(len(bottoms))