n=int(input())
S=input()
D={}
for i in range(len(S)):
    s=S[i]
    if s in D:D[s]+=1
    else:D[s]=1
for _ in range(n-1):
    S=input()
    E={}
    DD={}
    for i in range(len(S)):
        s=S[i]
        if s in E:E[s]+=1
        else:E[s]=1
    for i in D:
        if i in E:DD[i]=min(E[i],D[i])
    D=DD
ans=[]
for j in D:
    for _ in range(D[j]):
        ans.append(j)
ans.sort()
print("".join(ans))