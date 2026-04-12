import sys

N = int(input())
H = list(map(int, sys.stdin.readline().rsplit()))

maxi = 0
res = 0
for h in H:
    if maxi <= h:
        res += 1
        maxi = h

print(res)
