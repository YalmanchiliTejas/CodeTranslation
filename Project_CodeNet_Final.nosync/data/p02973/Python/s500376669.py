n = int(input())
a = [int(input()) for i in range(n)]
a = a[::-1]

from bisect import bisect_left, bisect_right

def lis(a):
    length = [a[0]]
    for i in range(1, len(a)):
        if a[i] >= length[-1]:
            length.append(a[i])
        else:
            length[bisect_right(length, a[i])] = a[i]
    return len(length)


print(lis(a))