h,w=map(int,input().split())
a=[]
for i in range(h):
    a.append(input())
H=[]
W=[]
for i in range(h):
    for j in range(w):
        if a[i][j]=="#":
            H.append(i)
            W.append(j)
H=set(H)
W=set(W)
for j in H:
    ans=[]
    for i in W:
        ans.append(a[j][i])
    print("".join(ans))
    
