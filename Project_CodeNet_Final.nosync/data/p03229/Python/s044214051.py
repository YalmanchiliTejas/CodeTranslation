import numpy as np
N=int(input())
A=[int(input()) for i in range(N)]
A=np.array(sorted(A))
ans=0

lenA=len(A)
mid=lenA//2

if lenA%2==0:
    ans+=A[mid]
    ans-=A[mid-1]
    if N>2:
        ans+=2*sum(A[mid+1:])
        ans-=2*sum(A[:mid-1])
else:
    ans+=A[mid]+A[mid+1]
    ans-=2*sum(A[:mid])
    
    tmp=2*sum(A[mid+1:])
    tmp-=A[mid]+A[mid-1]
    if N>3:
        ans+=2*sum(A[mid+2:])
        tmp-=2*sum(A[:mid-1])
    ans=max(ans,tmp)
print(ans)