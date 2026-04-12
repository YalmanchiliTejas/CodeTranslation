N,X,M=map(int,input().split())
A=[X]
A1=X
ans=0
for i in range(1,N):
    if 2*A1>M:
        A2=((M-A1)**2)%M
    else:
        A2=(A1**2)%M
    if A2 in A:
        num=A.index(A2)
        loop=i-num
        loop_A=A[num::]
        loop_val=sum(loop_A)
        rest=N-i
        x=rest%loop
        for _ in range(x):
            ans+=A[num]
            num+=1
        ans=ans+(rest//loop)*loop_val
        break
    else:
       A1=A2 
       A.append(A2)

print(sum(A)+ans)