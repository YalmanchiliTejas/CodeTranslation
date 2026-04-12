n,x=map(int,input().split())

a=[1]
p=[1]
for i in range(n):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)

def f(n,x):
    if x==0:
        return 0
    elif x==1:
        if n==0:
            return 1
        else:
            return 0

    elif 1<x<=(1+a[n-1]):
        return f(n-1,x-1)

    elif x==2+a[n-1]:
        return p[n-1]+1

    elif (2+a[n-1])<=x<=2+2*a[n-1]:
        return p[n-1]+1+f(n-1,x-2-a[n-1])

    else:
        return 2*p[n-1]+1

print(f(n,x))