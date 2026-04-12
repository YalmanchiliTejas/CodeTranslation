N = int(input())
A = [0]*N
for i in range(N):
    A[i] = int(input())
A.sort()
if N%2 == 1:
    print(max(sum(A[N//2+1:])*2-sum(A[:N//2-1])*2-sum(A[N//2-1:N//2+1]),sum(A[N//2+2:])*2-sum(A[:N//2])*2+A[N//2]+A[N//2+1]))
else:
    print(sum(A[N//2+1:])*2+A[N//2]-sum(A[:N//2-1])*2-A[N//2-1])
