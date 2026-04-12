n = int(input())
A = []
for i in range(n):
    A.append(int(input()))

A.sort()
if n&1:
    a = -sum(A[:n//2+1])*2 + sum(A[n//2+1:])*2 + A[n//2] + A[n//2-1]
    b = -sum(A[:n//2])*2 + sum(A[n//2:])*2 - A[n//2] - A[n//2+1]
    print(max(a,b))
else:
    ans = sum(A[n//2:])*2 - sum(A[:n//2])*2 - A[n//2] + A[n//2 - 1]
    print(ans)
