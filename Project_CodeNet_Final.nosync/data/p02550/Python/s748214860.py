n,x,m=map(int,input().split())

A,color=[x],["white" for _ in range(m)]
color[x]="black"
while 1:
    num=A[-1]**2%m
    if color[num]=="black":
        A.append(num)
        break
    else:
        color[num]="black"
        A.append(num)

fixed,loop=[],[]
point=A[-1]
flag=0
for i in A[:-1]:
    if i==point:flag=1

    if flag:loop.append(i)
    else:fixed.append(i)

ans=0
if n<=len(fixed):print(sum(fixed[:n]))
else:
    ans +=sum(fixed)
    div,mod=divmod(n-len(fixed),len(loop))
    ans +=div*sum(loop)
    ans +=sum(loop[:mod])
    print(ans)