import numpy as np

H,W=map(int,input().split())
a=[list(input()) for i in range(H)]
#a=np.array(a)
b=[]
c=[]
count1=0
count2=0
#print(a)
for i in range(H):
    l=a[i]
    #print(set(l),l[0])
    if not((len(set(l))==1)and(l[0]==".")):
        b.append(l)
        count1=count1+1
b=np.array(b)
b=b.T
b=b.tolist()
#print(b)
for i in range(W):
    l=b[i]
    #print(set(l),l[0])
    if not((len(set(l))==1)and(l[0]==".")):
        c.append(l)
        count2=count2+1
#print(c)
c=np.array(c)
c=c.T
c=c.tolist()
#print(c)
for i in c:print(*i,sep='')