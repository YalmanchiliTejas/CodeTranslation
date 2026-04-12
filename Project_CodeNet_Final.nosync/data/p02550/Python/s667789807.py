N,X,M = list(map(int,input().split()))
L = []
D = {}
L.append(X)
D[X] = D.get(X,0)+1
A = X
flag = 1
for i in range(N-1):
    A = A**2%M
    D[A] = D.get(A,0)+1
    if D[A]==2:
        flag=-1
        break
    else:
        L.append(A)
        if A==0:
            flag=0
            break
if flag==0:
    print(sum(L))
elif flag==1:
    print(sum(L))
else:
    LN = len(L)
    for i in range(LN):
        if L[i]==A:
            break
    Lu = L[i:]
    LuN = len(Lu)
    LuS = sum(Lu)
    out = 0
    if i!=0:
        out += sum(L[:i])
        N = N-i
    if N%LuN==0:
        out += LuS*(N//LuN)
        print(out)
    else:
        out += LuS*(N//LuN)
        amari = N%LuN
        out += sum(Lu[0:amari])
        print(out)