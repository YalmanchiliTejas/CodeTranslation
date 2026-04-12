
[H,W] = list(map(int,input().split()))

a = []
for i in range(H):
    a.append(list(input()))

# print(*a, sep='\n')

line = []
colu = []
for i in range(H):
    for j in range(W):
        if a[i][j] == '#':
            line.append(i)
            colu.append(j)
# print('line:', line)
# print('culu:', colu)

ans=[]
for i in range(H):
    dammy=[]
    for j in range(W):
        if (i in line) and (j in colu):
            dammy.append(a[i][j])
    if dammy!=[]:
        ans.append(dammy)

for i in range(len(ans)):
    print(''.join(ans[i]))
#print(*ans)
