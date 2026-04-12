import bisect
n = int(input())
A = list(int(input()) for _ in range(n))
B = [A[n-1]]

for i in range(n-2,-1,-1):
    if A[i] >= B[-1]:
        B.append(A[i])
    else:
        B[bisect.bisect_right(B,A[i])] = A[i]
print(len(B))
