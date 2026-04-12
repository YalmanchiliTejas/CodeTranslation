N=int(raw_input())
A=[int(x) for x in raw_input().split()]
B=[[0 for x in range(N+1)] for y in range(N)]
for i in range(N):
    B[i][i+1]=A[i]
for l in range(1,N):
    for i in range( N-l):
        B[i][i+l+1]=max(A[i]-B[i+1][i+l+1], A[i+l] - B[i][i+l]  )
print B[0][N]
#for ll  in B:
#    print ll
