h,w=map(int,input().split())
A=[]
for i in range(h):
    A.append(input())

#print(A)

H=[0 for i in range(h)]
W=[0 for i in range(w)]

for i in range(h):
    if A[i]=="."*w :
        H[i]=1
for i in range(w):
    co=0
    for j in range(h):
        if A[j][i]=="." :
            co+=1
    if co==h :
        W[i]=1


B=[]

for i in range(h):
    st=""
    if H[i]==0 :
        for j in range(w):
            if W[j]==0:
                st+=A[i][j]
        print(st)
