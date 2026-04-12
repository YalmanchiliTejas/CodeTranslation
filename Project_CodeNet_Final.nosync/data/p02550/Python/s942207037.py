N,X,M=map(int,input().split())
A = [X,]
setA = {X,}
alast=X
flag=False
for i in range(min(N-1,M)):
    P=alast**2%M
    if P in setA:
        flag=True
        d = A.index(P)
        C=A[d:]
        alast=P
        break
    else:
        A.append(P)
        setA.add(P)
        alast=P
if flag:
    if alast==0:
        ans = sum(A)
    else:
        res = (N-d)%len(C)
        ans = sum(A[:d])+((N-d)//len(C))*sum(C) + sum(C[:res])
else:
    ans = sum(A) 
print(ans)