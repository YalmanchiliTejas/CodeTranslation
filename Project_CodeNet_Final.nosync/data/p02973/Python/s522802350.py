import bisect

n = int(input())
seq = []
for i in range(n):
    seq.append(int(input()))
seq.reverse()
LIS = [seq[0]]
for i in range(1,len(seq)):
    if seq[i] >= LIS[-1]:
        LIS.append(seq[i])
    else:
        LIS[bisect.bisect_right(LIS, seq[i])] = seq[i]

print(len(LIS))