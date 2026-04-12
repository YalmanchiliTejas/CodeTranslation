#107b
import numpy as np

def trans(l):
    l=np.array(l)
    l=l.T
    l=l.tolist()
    return l

h,w=map(int,input().split())
temp1=[]
temp2=[]
ans=[]

for i in range(h):
    ans.append(list(input()))

for i in ans[:]:
    if set(i)!={'.'}:
        temp1.append(i)

     
ans=trans(temp1)

for i in ans[:]:
    if set(i)!={'.'}:
        temp2.append(i)

ans=trans(temp2)
        
for i in ans:
    print(''.join(i))