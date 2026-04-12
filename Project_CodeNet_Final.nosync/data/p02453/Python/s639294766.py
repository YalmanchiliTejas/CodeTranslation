import bisect

n = int(input())
A = [int(x) for x in input().split()]
q = int(input())

for i in range(q):
    k = int(input())
    print(bisect.bisect_left(A, k))

