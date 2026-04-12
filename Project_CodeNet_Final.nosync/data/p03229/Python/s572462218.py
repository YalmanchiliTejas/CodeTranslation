N=int(input())
A=[]
for i in range(0,N):
    a=int(input())
    A.append(a)

A.sort()

if N%2==0:
    k=N//2
    ans=2*sum(A[k:N])-A[k]-(2*sum(A[0:k])-A[k-1])
    print(ans)
else:
    k=N//2
    ans1=2*sum(A[k+1:N])-2*(sum(A[0:k+1]))+A[k]+A[k-1]
    ans2=2*sum(A[k:N])-A[k]-A[k+1]-2*sum(A[0:k])
    print(max(ans1,ans2))