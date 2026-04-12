import copy
N,M=map(int,raw_input().split())
v=[False for _ in range(N+1)]
v[0]=True
s=[map(int,raw_input().split()) for _ in range(M)]

def recursion(V,p):
    m=0
    for a,b in s:
        if p==a :
            if V[b]:
                continue
            else:
                tmp=copy.deepcopy(V)
                tmp[b]=True
                if all(tmp):
                    m+=1
                else:
                    m+=recursion(tmp,b)
        elif p==b :
            if V[a]:
                continue
            else:
                tmp=copy.deepcopy(V)
                tmp[a]=True
                if all(tmp):
                    m+=1
                else:
                    m+=recursion(tmp,a)
    return m

v[1]=True
print recursion(v,1)