import sys
import bisect
input = sys.stdin.readline

n = int(input())


colour_list = [-int(input())]
c = len(colour_list)


for i in range(n-1):
    a = -int(input())
    b = bisect.bisect(colour_list,a)
    if b != c:
        colour_list[b] = a
    else:
        colour_list.append(a)
        c += 1

print(c)
