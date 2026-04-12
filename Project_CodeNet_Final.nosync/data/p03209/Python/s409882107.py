N,X=map(int,input().split(' '))
l = 1
p = 1
L=[]
P=[]
for i in range(N):
    l = 2*l+3
    p = 2*p+1
    L.append(l)
    P.append(p)
def pans(l,x):
    if l==1:
        return list('BPPPB'[:x]).count('P')
    elif x<=L[l-2]+1:
        return pans(l-1,x-1)
    else:
        return P[l-2]+1+pans(l-1,x-(2+L[l-2]))
print(pans(N,X))