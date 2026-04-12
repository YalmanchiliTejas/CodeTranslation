N=int(input())
A=[int(i) for i in input().split()]
ans=0
while max(A)>N-1:
    A.sort()
    t=A[-1]//N
    A[-1]=A[-1]-t*N
    ans+=t
    for i in range(N-1):
        A[i]+=t
print(ans)