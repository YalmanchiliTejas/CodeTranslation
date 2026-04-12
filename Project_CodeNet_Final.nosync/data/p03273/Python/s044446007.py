h,w=map(int,input().split())

grid=[[0 for j in range(w)] for i in range(h)]
tate=[]
ans=[]
for i in range(h):
    b=input()
    for j in range(w):
        grid[i][j]=b[j]

for j in range(w):
    cnt=0
    for i in range(h):
        if grid[i][j]=='.':
            cnt+=1
        
        if cnt==h:
            tate.append(j)

if len(tate)>1:
    tate=[n-i for i,n in enumerate(tate)]

for j in tate:
    for i in grid:
        i.pop(j)

for i in grid:
    if i.count('.')!=len(i):
        ans.append(i)

for i in ans:
    print(''.join(i))