import sys
input = sys.stdin.readline

def LIS(L):
    from bisect import bisect
    seq = []
    for a in L:
        pos = bisect(seq, a)
        if len(seq) <= pos:
            seq.append(a)
        else:
            seq[pos] = a
    return len(seq)

n = int(input())
a = []
for _ in range(n):
    a.append(int(input()))
print(LIS(a[::-1]))
