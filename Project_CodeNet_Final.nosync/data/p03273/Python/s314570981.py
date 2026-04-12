H,W=map(int,input().split())
Map=[]
MAP=[]
Key=[]
cnt=0
import numpy as np

for i in range(H):
    tmp=input()
    if tmp!='.'*W:
        Map.append(tmp)
        
for i in Map:
    MAP.append(list(i))
    
for i in range(W):
    for j in range(len(MAP)):
        if MAP[j][i]=='.':
            cnt+=1
    if cnt==len(Map):
        Key.append(i)
    cnt=0

MAP=np.delete(MAP,Key,1)

for i in MAP:
    a=''.join(i)
    print(a)