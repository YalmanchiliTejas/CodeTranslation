h,w=map(int,input().split())
M=list(input() for _ in range(h))
c=[]
for i in range(h):
    if "#" not in M[i]:
        c.append(i)
for dot in c[::-1]:
    M.pop(dot)

c=[]
col=[]
for i in range(len(M[0])):
    flag=1
    for j in range(len(M)):
        if "#" in M[j][i]:flag=0
    if flag==1:c.append(i)

for i in c[::-1]:
    for row in M:
        list(row).pop(i)
for i in range(len(M)):
    flag=0
    for j in range(len(M[0])):
        if j not in c:
            print(*M[i][j],end="")
            flag=1
    if i<len(M)-1 and flag==1:print()    