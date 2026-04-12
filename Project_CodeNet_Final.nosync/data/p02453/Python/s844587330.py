import bisect

n = int(input())
A = list(map(int, input().split()))
q = int(input())

for i in range(q):
    query = int(input())
    print(bisect.bisect_left(A, query))
