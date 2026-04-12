n,x,m= list(map(int, input().strip().split()))
t=0
b=[]
b.append(x)
for i in range(m+1):
        if b[-1]**2%m in b:
            b.append(b[-1]**2%m)
            break
        else:
            b.append(b[-1]**2%m)
        
l=len(b) 
for i in range(l-1):
    if b[i]==b[l-1]:
        q=i
w=l-2-q+1
s=0
for i in range(q):
    s+=b[i]
t=0
for i in range(q,l-1):
    t+=b[i]
u=(n-q)//w
v=(n-q)%w
ans=0
for i in range(q,q+v):
    ans+=b[i]
ans+=s+u*t

print(ans)
    