n=int(input())
a=[]
s1=0
s2=0
for i in range(n):
    t=int(input())
    a.append(t)
a.sort()
if n==2:
    print(a[1]-a[0])
elif n%2==0:
    m=(n-2)//2
    
    for i in range(m):
        s1=s1-2*a[i]
    s1=s1-a[m]
    s1=s1+a[m+1]
    for i in range(m+2,n):
        s1=s1+2*a[i]
    print(max(s1,s2))
elif n==3:
    print(max((a[2]-a[0]+a[1]-a[0]),(a[2]-a[1]+a[2]-a[0])))
elif n%2==1:
    m=(n-2)//2
    
    for i in range(m):
        s1=s1-a[i]*2
    s1=s1-a[m]
    s1=s1-a[m+1]
    for i in range(m+2,n):
        s1=s1+2*a[i]
    
    for i in range(m+1):
        s2=s2-a[i]*2
    s2=s2+a[m+1]
    s2=s2+a[m+2]
    for i in range(m+3,n):
        s2=s2+2*a[i]
    
    print(max(s1,s2))