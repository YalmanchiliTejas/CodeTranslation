import numpy as np

H,W = list(map(int,input().split()))

#print(H,W)

dot=[]
for h in range(H):
    d=input().strip()
    if '#' in d:
        dot.append(list(d))
    
#print(dot)
dot = np.array(dot).T

dot2=[]
for d in range(len(dot)):
    if '#' in dot[d]:
        dot2.append(dot[d])

dot2 = np.array(dot2).T

#print(dot2)

for h in range(len(dot2)):
    print("".join(dot2[h]))