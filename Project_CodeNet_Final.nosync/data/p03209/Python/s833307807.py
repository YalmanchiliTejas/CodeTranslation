N,X=map(int,input().split())
H=[1]
P=[1]

for i in range(N):
    H.append(H[i]*2+3)
    P.append(P[i]*2+1)

def f(n,x):
    if n==0:
        return  1
    else:
        if x==1:
            return 0
        elif x<2+H[n-1]:
            return f(n-1,x-1)
        elif x==2+H[n-1]:
            return P[n-1]+1
        elif x<H[n]:
            return P[n-1]+f(n-1,x-H[n-1]-2)+1
        elif x==H[n]:
            return P[n]
print(f(N,X))