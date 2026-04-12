import bisect
N = int(input())
A = [int(input()) for _ in range(N)]
first = [-1 for _ in range(N)]
for a in A:
    i = bisect.bisect_left(first,a)
    first[i-1] = a
ctr = N
for f in first:
    if f == -1:
        ctr -= 1
print(ctr)