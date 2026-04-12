n,x=map(int,input().split())

cnt=1
p=1
C=[0]*(n+1)
C[0]=1
for i in range(1,n+1):
    cnt=cnt*2+3
    C[i]=cnt

def mid(n):
    return (C[n]-1)//2


def f(n,l):
    if n==0:
        return 1
        
    if l==mid(n):
        return f(n-1,mid(n-1)*2)+1
    elif l==mid(n)*2:
        return f(n-1,mid(n-1)*2)*2+1
    elif l==0:
        return 0
    elif 0<l and l<mid(n):
        return f(n-1,l-1)
    else:
        return f(n-1,2*mid(n-1))+1+f(n-1,l-mid(n)-1)
print(f(n,x-1))