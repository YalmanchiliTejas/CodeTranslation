from bisect import bisect_left



n = int(input())

A = tuple(map(int, input().split()))

q = int(input())


for _ in range(q):

    k = int(input())

    print(bisect_left(A, k))

