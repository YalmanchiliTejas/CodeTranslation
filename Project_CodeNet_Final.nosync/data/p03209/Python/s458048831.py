n,x=map(int,input().split())
a=[1]
p=[1]
for i in range(n):
    a.append(a[-1]*2+3)
    p.append(p[-1]*2+1)

def num(n,x):
    if n==0 or x<=0:
        return 0 +(x>0)
    elif x<=a[n-1]+1:
        return num(n-1,x-1)
    else:
        return p[n-1]+1+num(n-1,x-a[n-1]-2)

print(num(n,x))