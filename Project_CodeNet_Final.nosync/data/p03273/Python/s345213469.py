h,w=map(int,input().split())
l=[[] for i in range(h)]
g=[]
r=[]
ans=[[] for i in range(h)]
for i in range(h):
    l[i]=list(input())
for i in range(h):
    if not all(l[i][j]=="." for j in range(w)):
        g.append(i)

for x in range(w):
    if not all(l[j][x]=="." for j in range(h)):
        
        r.append(x)
for i in g:
    for j in r:
        ans[i].append(l[i][j])
for i in g:
    print("".join(ans[i]))

    
               
