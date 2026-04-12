N,X,M=map(int,input().split())
A=[X]
x=(A[0]**2)%M
i=0
while not x in A:
    A.append(x)
    i+=1
    x=(x**2)%M

loopid=A.index(x)
looplen=i-loopid+1
loopsum=sum(A[loopid:])
startsum=sum(A[:loopid])

ans=0
if N-1<loopid:
    ans=sum(A[:N])
else:
    loopnum=(N-1-loopid+1)//looplen if looplen else N-1-loopid
    rest=N-1-(loopid+looplen*loopnum)+1
    ans+=startsum
    ans+=loopnum*loopsum
    ans+=sum(A[loopid:loopid+rest])
print(ans)
