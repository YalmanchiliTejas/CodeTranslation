from collections import*
n,*a=map(int,open(0).read().split())
a.sort()
d=len(a)//2
flag=0
if len(a)%2==1:
    b=a[:d+1]
    c=a[d+1:]
    flag=1
else:
    b=a[:d]
    c=a[d:]
l=[]
for i in range(d):
    l.append(c[i])
    l.append(b[i])
if flag:
    if abs(l[-1]-b[-1])>abs(l[0]-b[-1]):
        l.append(b[-1])
    else:
        l.insert(0,b[-1])
print(sum(abs(l[i+1]-l[i])for i in range(n-1)))
