import numpy as np
n,m=map(int,input().split())
arr=[]
for i in range(n):
    l=[ord(c)-46 for c in input()]
    if l.count(0)==m:
        continue
    arr.append(l)
a=np.array(arr)
a=a.T
b=[]
for i in range(len(a)):
    if list(a[i]).count(0)==len(a[i]):
        continue
    b.append(list(a[i]))
b=list(np.array(b).T)
for l in b:
    for x in l:
        if x==0:
            print(".",end="")
        else:
            print("#",end="")
    print()
