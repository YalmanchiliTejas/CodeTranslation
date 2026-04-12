import numpy as np
WH='.'
BK='#'
x=input()
x=x.split()
H=int(x[0])
W=int(x[1])
a=[[] for i in range(H)]
num=[]
numnum=0
for i in range(H):
    x=input()
    for j in range(W):
        a[i].append(x[j])
for i in range(H):
    flag=0
    for j in range(W):
        if a[i][j]==WH:
            flag=flag+1
        else:
            flag=flag-1
    if flag==W:
        num.append(i)
        numnum=numnum+1
for i in range(numnum):
    a.pop(num[i]-i)
H=H-numnum
a_n=np.array(a)
tr=a_n.T
a=tr.tolist()
num=[]
numnum=0
num_num=0
for i in range(W):
    flag=0
    for j in range(H):
        if a[i][j]==WH:
            flag=flag+1
        else:
            flag=flag-1
    if flag==H:
        num.append(i)
        numnum=numnum+1
        flag=0
    else:
        flag=0
for i in range(numnum):
    a.pop(num[i]-i)
W=W-numnum
a_n=np.array(a)
a=a_n.T
for i in range(H):
    ans=''
    for j in range(W):
        ans=ans+a[i][j]
    print(ans)