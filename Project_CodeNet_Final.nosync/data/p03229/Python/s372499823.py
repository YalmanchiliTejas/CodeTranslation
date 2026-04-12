N = int(input())
A = [int(input()) for i in range(N)]
A.sort()
if N & 1:
    ans1 = 2*sum(A[N//2:])-A[N//2]-A[N//2+1]-2*sum(A[:N//2])
    ans2 = 2*sum(A[N//2+1:])-2*sum(A[:N//2+1])+A[N//2]+A[N//2-1]
else:
    if N == 2:
        ans1 = ans2 = abs(A[0]-A[1])
    else:
        ans1 = 2*sum(A[N//2:])-A[N//2]-2*sum(A[:N//2])+A[N//2-1]
        ans2 = 2*sum(A[N//2+1:])-A[N//2+1]-2*sum(A[:N//2+1])+A[N//2]
print(max(ans1, ans2))
