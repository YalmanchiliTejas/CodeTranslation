from bisect import bisect as bisect
def LIS(l):
    seq = []
    for a in l:
        i = bisect(seq,a)
        if len(seq)==i:
            seq.append(a)
        else:
            seq[i]=a
    return len(seq)

N = int(input())
A = [-int(input()) for _ in range(N)]
print(LIS(A))