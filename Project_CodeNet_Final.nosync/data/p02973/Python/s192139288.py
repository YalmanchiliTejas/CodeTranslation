import bisect

N = int(input())
ans = 0
X = [int(input())for _ in range(N)]
A = []
for a in X[::-1]:
    if len(A) == 0:
        A.append(a)
    elif A[-1] <= a:
        A.append(a)
    else:
        i = bisect.bisect_right(A, a)
        A[i] = a

print(len(A))

