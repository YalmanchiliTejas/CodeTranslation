n,x=map(int,input().split())

a,p=[1],[1]
for i in range(n):
    a.append(2*a[i]+3)
    p.append(2*p[i]+1)

def F(N,X):
    if N==0:
        return 0 if X<=0 else 1

    elif X==1:
        return 0
    
    elif 1<X<=1+a[N-1]:
        return F(N-1,X-1)

    elif X==2+a[N-1]:
        return p[N-1]+1

    elif 2+a[N-1]<X<=a[N]-1:
        return F(N-1,X-(2+a[N-1]))+p[N-1]+1

    elif X==a[N]:
        return 2*p[N-1]+1

print(F(n,x))