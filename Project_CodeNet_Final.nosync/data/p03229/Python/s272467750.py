N=int(input())
A=[]

for i in range(N):
    A.append(int(input()))

A.sort()
if N%2==0:
    A1=A[0:N//2]
    A2=A[N//2:]
    ans=(2*sum(A2)-A2[0])-(2*sum(A1)-A1[-1])
else:
    A1=A[0:N//2]
    A2=A[N//2+1:]
    ans=(2*sum(A2)-A2[0])-(2*sum(A1)-A1[-1])
    add=max(A[N//2]-A1[-1],A2[0]-A[N//2])
    ans+=add
print(ans)
