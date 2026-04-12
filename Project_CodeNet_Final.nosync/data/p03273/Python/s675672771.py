h,w=map(int,input().split())
S=[]
for i in range(h):
    s=input()
    if all([k=="." for k in s]):
        continue
    S.append(s)
if len(S)!=0:
    C=[]
    for j in range(w):
        if all([S[i][j]=="." for i in range(len(S))]):
            C.append(j)

for i in range(len(S)):
    for j in range(w):
        if j in C:
            continue
        print(S[i][j],end="")
    print("",end="\n")