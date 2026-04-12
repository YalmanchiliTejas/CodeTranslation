h,w=map(int,input().split())
r=[]
for i in range(h):
    r.append(list(input()))
t=[]
for i in range(h):
    for j in range(w):
        if r[i][j]=='#':
            t.append([i,j])
op=[[[0,0]]]
for i in range(h+w-2):
    tmp=[]
    for j in op:
        tmp.append(j+[[j[-1][0]+1,j[-1][1]]])
        tmp.append(j+[[j[-1][0],j[-1][1]+1]])
    op=tmp
for i in op:
    if sorted(i)==sorted(t):
        print('Possible')
        exit()
print('Impossible')
