import numpy as np
h,w=input().split()
h,w=int(h),int(w)
x3=[]
for i in range(h):
    x1=input()
    if x1 !=  w*".":
        x3.append(list(x1))

x3=np.array(x3).T.tolist()
x4=[]
for i in range(w):
    if x3[i] != ["." for i in range(len(x3[i]))]:
        x4.append(x3[i])

x4=np.array(x4).T.tolist()
for i in range(len(x4)):
    for j in range(len(x4[0])):
        print(x4[i][j],end="")
    print()
