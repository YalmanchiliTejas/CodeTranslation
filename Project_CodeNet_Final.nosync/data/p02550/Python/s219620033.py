N,X,M=map(int,input().split())
a=[0]*(M)
A=X%M
a[A]=1
ans=A
Ans=[A]
flag=0
for i in range(N-1):
    A=A*A%M
    if A==0:
        break
    if a[A]==1:
        flag=1
        break
    a[A]=1
    ans+=A
    Ans.append(A)
if flag==1:
    for num in range(len(Ans)):
        if A==Ans[num]:
            break
    n=len(Ans)-num
    b=sum(Ans[:num])
    x=(N-num)//n
    y=(N-num)%n
    Sum=b+(ans-b)*(x)+sum(Ans[num:y+num])
else:
    Sum=sum(Ans)
print(Sum)