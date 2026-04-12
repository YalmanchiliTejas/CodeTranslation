N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()
n = N//2
if N%2 != 0:
    ans1,ans2,ans = 0,0,0
    ar1,ar2 = A[:n],A[n+1:]
    ar = []
    for i in range(n):
        ar.append(ar2[i])
        ar.append(ar1[i])
    ar.append(A[n])
    for i in range(N-1):
        ans1 += abs(ar[i]-ar[i+1])
    ar = [A[n]]+ar[:-1]
    for i in range(N-1):
        ans2 += abs(ar[i]-ar[i+1])
    ans = max(ans1,ans2)
else:
    ans = 0
    ar1,ar2 = A[:n],A[n:]
    ar = []
    for i in range(n):
        ar.append(ar2[i])
        ar.append(ar1[i])
    for i in range(N-1):
        ans += abs(ar[i]-ar[i+1])
 
print(ans)