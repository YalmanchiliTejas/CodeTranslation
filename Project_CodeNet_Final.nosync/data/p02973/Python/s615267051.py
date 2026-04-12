import sys
aa=list(map(int,sys.stdin.read().split()))
aa=aa[1:aa[0]+1]
n=len(aa)
import bisect
bb=[]
for i in range(n):
    if not bb:
        bb.append(aa[-i-1])
    else:
        if bb[-1] <= aa[-i-1]:
            bb.append(aa[-i-1])
        else:
            j = bisect.bisect_right(bb,aa[-i-1])
            bb[j] = aa[-i-1]
print(len(bb))