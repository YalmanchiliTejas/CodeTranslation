import numpy as np

h,w=map(int,input().split())
tmp=[]
for i in range(h):
        a=list(input())
        tmp.append(a)
ans1=[]
if(w!=1):
    for i in range(h):
        if(len(set(tmp[i]))==1 and tmp[i][0]!="#"):
            ans1.append(i)
ans2=[]
tmp=list(map(list,zip(*tmp)))
if(h!=1):
    for i in range(w):
        if(len(set(tmp[i]))==1 and tmp[i][0]!="#"):
            ans2.append(i)
# print(ans1,ans2)
tmp=list(map(list,zip(*tmp)))
tmp=np.delete(tmp,ans1,axis=0)
tmp=np.delete(tmp,ans2,axis=1)
for i in range(len(tmp)):
    for j in range(len(tmp[0])):
        print(tmp[i][j],end="")
    print()