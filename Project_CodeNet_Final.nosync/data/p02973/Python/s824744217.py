import bisect

N = int(input())

A = []

for i in range(N):

    a = int(input())
    A.append(a)

A.reverse()

seq = [float("-inf")]

for i in A:

    ind = bisect.bisect_right(seq,i)

    if ind == len(seq):
        seq.append(i)
    else:
        seq[ind] = i

print (len(seq)-1)

