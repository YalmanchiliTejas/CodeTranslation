n,x,m=[int(i) for i in raw_input().split()]
x%=m
a=[x]
d={}
d[x]=0
pos=-1
for i in range(1,min(n,100000)):
    t=(a[-1])**2
    t%=m
    if(d.get(t,-1)!=-1):
        pos=d[t]
        break
    d[t]=i
    a.append(t)
s=0
for i in a:
    s+=i
if pos!=-1:
    n-=len(a)
    a=a[pos:]
    s1=0
    for i in a:
        s1+=i
    s+=s1*(n/len(a))
    n%=len(a)
    for i in range(n):
        s+=a[i]
print s
