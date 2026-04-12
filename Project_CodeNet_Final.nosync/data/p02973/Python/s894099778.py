import sys
import bisect

stdin = sys.stdin
 
ri = lambda: int(rs())
rl = lambda: list(map(int, stdin.readline().split()))
rs = lambda: stdin.readline().rstrip()  # ignore trailing spaces

N = ri()
A = [10 ** 10 - ri() for _ in range(N)]
l = []
for a in A:
    i = bisect.bisect_right(l, a)
    if i == len(l):
        l.append(a)
    else:
        l[i] = a

print(len(l))
#39
