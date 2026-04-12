n,x=[int(i)  for i in input().split()]
a=[1]
p=[1]
for i in range(n):
    a.append(a[i]*2+3)
    p.append(p[i]*2+1)
def f(n,x):
    if n==0:
        if x==0:
            return 0
        else:
            return 1
    elif n>=1:
        if x==1:
            return 0
        elif 1<x<=1+a[n-1]:
            return f(n-1,x-1)
        elif x==a[n-1]+2:
            return p[n-1]+1
        elif 2+a[n-1]<x<=2*a[n-1]+2:
            return p[n-1]+1+f(n-1,x-2-a[n-1])
        else:
            return 2*p[n-1]+1

print(f(n,x))