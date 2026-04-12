arr=[]
from collections import Counter
c=Counter([])
inp=list(map(int,input().split()))
n=inp[0]
x=inp[1]
m=inp[2]
sumi=x
c=Counter([])
c[x]=1
a=(x**2)%m
arr=[x]
z=2
flag=0
sz=1
while 1:
    if c[a]!=0 :
        flag=1
        break
    arr.append(a)
    sz+=1
    c[a]+=1
    a=(a**2%m)
    if sz==n:
        break
if flag==0:
    print (sum(arr))
else:
    ind=arr.index(a)
    s=sum(arr[:ind])
    s1=sum(arr[ind:])
    s+=s1
    l=len(arr)-ind
    n-=len(arr)
    x=n//l
    s+=s1*x
    x=n%l
    s+=sum(arr[ind:ind+x])
    print (s)