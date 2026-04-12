H,W=map(int,input().split())
b=[]
for i in range(H):
    a=list(str(input()))
    if '#' in a:
        b.append(a)

count=[0]*W

for i in b:

    for j in range(W):

        if i[j]=='#':
            count[j] += 1

ans=['']*len(b)

for i in range(len(b)):

    for j in range(W):

        if count[j]!=0:
            
            ans[i] += b[i][j]

for k in ans:

    print(k)


