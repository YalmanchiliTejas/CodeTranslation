# C - Align
N = int(input())
A = [0]+[int(input()) for _ in range(N)]
A = sorted(A)
ans = 0
if N%2==0:
    i = 1
    while i<N//2:
        ans -= 2*A[i]
        i += 1
    ans -= A[i]
    i += 1
    ans += A[i]
    i += 1
    while i<=N:
        ans += 2*A[i]
        i += 1
else:
    i = 1
    while i<N//2:
        ans -= 2*A[i]
        i += 1
    ans -= A[i]
    i += 1
    ans -= A[i]
    i += 1
    while i<=N:
        ans += 2*A[i]
        i += 1
    tmp = 0
    A = [0]+sorted(A[1:], reverse=True)
    i = 1
    while i<N//2:
        tmp += 2*A[i]
        i += 1
    tmp += A[i]
    i += 1
    tmp += A[i]
    i += 1
    while i<=N:
        tmp -= 2*A[i]
        i += 1
    ans = max(ans,tmp)
print(ans)