from bisect import bisect_right
def LIS(l):
    length = [l[0]]
    for i in range(1, len(l)):
        if l[i] >= length[-1]:
            length.append(l[i])
        else:
            pos = bisect_right(length, l[i])
            length[pos] = l[i]
    return len(length)

n = int(input())
a = [int(input()) for i in range(n)]
a = a[::-1]
print(LIS(a))
