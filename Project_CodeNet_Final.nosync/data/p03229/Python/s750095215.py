n=int(input())
l=[int(input()) for _ in range(n)]
l.sort()
m=sorted((-1)**(i+1) if i==0 or i==n-1 else 2*((-1)**(i+1)) for i in range(n))
f=lambda x,y:x*y
a=abs(sum(map(f,l,m)))
b=abs(sum(map(f,l[::-1],m)))
print(max(a,b))