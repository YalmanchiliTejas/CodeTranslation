N = int(input())
A = [int(input()) for _ in range(N)]
A.sort()

if N%2==0: 
    ans = 2*sum(A[N//2+1:N]) + A[N//2]
    ans -= 2*sum(A[0:N//2-1]) + A[N//2-1]

    print(ans)
else :
    lsl = 2*sum(A[N//2+2:N]) + A[N//2+1] + A[N//2]
    lsl -= 2*sum(A[0:N//2])

    sls = 2*sum(A[N//2+1:N])
    sls -= 2*sum(A[0:N//2-1]) + A[N//2-1] + A[N//2]

    print(max(lsl, sls))