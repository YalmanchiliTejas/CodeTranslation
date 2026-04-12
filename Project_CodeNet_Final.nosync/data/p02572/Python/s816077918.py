N=int(input())
A=list(map(int,input().split()))
A.reverse()
ans=0
tempsum=0
for i in range(len(A)-1):
    tempsum+=A[i]
    ans=ans+tempsum*A[i+1]

print(ans%(10**9+7))