N,X=list(map(int,input().split()))
p=[]
a=[]
def search(N):
    if N==0:
        p.append(1)
        a.append(1)
        return 1,1
    else:
        search(N-1)
        p.append(2*p[N-1]+1)
        a.append(2*a[N-1]+3)
search(N)
def bug(N,X):#p,a
    if N==0 and X>=1:return 1
    if X==1:return 0
    if 1<X<=1+a[N-1]:
        return bug(N-1,X-1)
    elif X==a[N-1]+2:
        return p[N-1]+1
    elif a[N-1]+2<X<=2+2*a[N-1]:
        return p[N-1]+1+bug(N-1,X-2-a[N-1])
    elif X==3+2*a[N-1]:
        return 2*p[N-1]+1
print(bug(N,X))