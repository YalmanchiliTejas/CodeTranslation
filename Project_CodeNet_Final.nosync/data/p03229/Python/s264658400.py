import itertools

n=int(input())
a=list(int(input()) for i in range(n))
b=[]
a.sort()
ans=0

if n%2==1:
    x=2*sum(a[n//2+1:])-2*sum(a[:n//2+1])+sum(a[n//2-1:n//2+1])
    y=2*sum(a[n//2:])-sum(a[n//2:n//2+2])-2*sum(a[:n//2])
    print(max(x,y))

else:
    x=2*sum(a[n//2:])-(a[n//2]) -2*sum(a[:n//2])+a[n//2-1]
    print(x)
        
        
        


