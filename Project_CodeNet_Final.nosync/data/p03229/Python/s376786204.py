n=int(input())
a=[]
for i in range(n):
    b=int(input())
    a.append(b)
a.sort()
b=a

if n%2==0:
    for i in range(int(n/2-1)):
        a[int((n/2))+1+i]=2*a[int((n/2))+1+i]
        a[i]=-2*a[i]
    a[int(n/2)-1]=(-1)*a[int(n/2)-1]   
    print(sum(a))
else:
    for i in range(int(n/2)):
        a[int((n/2))+1+i]=2*a[int((n/2))+1+i]
        a[i]=-2*a[i]
    a[int(n/2)]=(-1)*a[int(n/2)]
    a[int(n/2)-1]=a[int(n/2)-1]*0.5     
    c=sum(a)
    
    b[int(n/2)+1]=0.5*b[int(n/2)+1]
    b[int(n/2)]=(-1)*b[int(n/2)]
    b[int(n/2)-1]=2*b[int(n/2)-1]
    d=sum(b)
    print(int(max(c,d)))

       