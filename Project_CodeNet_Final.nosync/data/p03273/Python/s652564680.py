h,w=map(int,input().split())
a=[list(input()) for i in range(h)]
#print(a)
H=[]
W=[]
for i in range(h):
    count=0
    for j in range(w):
        if a[i][j]==".":
            count+=1
    if count==w:
        H.append(i)
for i in range(w):
    count=0
    for j in range(h):
        if a[j][i]==".":
            count+=1
    if count==h:
        W.append(i)
for i in range(1,len(H)+1):
    for j in range(w):
        a[H[-1*i]][j]=""
for i in range(1,len(W)+1):
    for j in range(h):
        a[j][W[-1*i]]=""

for i in range(h):
    if not ("." in a[i] or "#" in a[i]):
        continue
    print("".join(a[i]))
