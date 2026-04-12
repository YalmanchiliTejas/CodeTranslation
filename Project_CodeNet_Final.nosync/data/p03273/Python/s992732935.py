H,W=map(int,input().split())
lsa=[]
#lsacom=[]
dcomi={}
dcomj={}
for i in range(H):
    lsa.append(input())
for i in range(H):
    for j in range(W):
        if lsa[i][j]=="#":
            break
    else:
        dcomi[i]=1
for j in range(W):
    for i in range(H):
        if lsa[i][j]=="#":
            break
    else:
        dcomj[j]=1
for i in range(H):
    for j in range(W):
        if (not i in dcomi) and (not j in dcomj):
            print(lsa[i][j],end="")
    if not i+1 in dcomi:
        print()
