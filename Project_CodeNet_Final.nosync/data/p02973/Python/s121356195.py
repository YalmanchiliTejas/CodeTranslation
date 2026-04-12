import bisect
N = int(input())
A = []
for i in range(N):
    a = int(input()) * (-1)
    b = bisect.bisect_right(A,a)
    if b == len(A):
        A.append(a)
    else:
        A[b] = a
print(len(A))