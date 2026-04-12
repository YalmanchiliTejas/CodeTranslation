import sys
input = sys.stdin.readline
import bisect
N = int(input())
a = [-int(input()) for i in range(N)]
ls = []
res = 0
for elem in a:
    idx = bisect.bisect_right(ls,elem)
    if idx == res:
        ls.append(elem)
        res += 1
    else:
        ls[idx] = elem
print(res)
