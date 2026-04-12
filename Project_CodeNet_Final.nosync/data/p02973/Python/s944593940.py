N = int(input())
A = [int(input()) for i in range(N)]

import bisect

bilist = [A[0]]
ans = 0

for a in A[1:]:
    index = bisect.bisect_left(bilist,a)
    if index == 0:
        bisect.insort_left(bilist,a)
    else:
        bilist[index-1] = a


print(len(bilist))


    