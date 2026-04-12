from bisect import bisect
N, *A = map(int, open(0).read().split())

mins = []
length = 0
for a in A:
    i = bisect(mins, -a)
    if i >= length:
        mins.append(-a)
        length += 1
    else:
        mins[i] = -a
print(length)