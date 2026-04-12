h,w=map(int,input().split())
a=[input() for _ in range(h)]
#print(a)
A=[]
for i in range(h):
    if "#" in a[i]:
        A.append(a[i])
#print(A)
l=[]
for i in range(len(A[0])):
    x=0
    for j in range(len(A)):
        if A[j][i]==".":
            x+=1
    if x==len(A):
        l.append(i)
#print(l)
for i in range(len(A)):
    ans=""
    for j in range(len(A[0])):
        if j in l:
            continue
        else:
            ans+=A[i][j]
    print(ans)