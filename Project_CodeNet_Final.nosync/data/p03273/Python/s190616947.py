h,w = map(int,input().split())
mx = []
for i in range(h):
    mx.append(list(map(str, input().split())))
for i in range(h-1,-1,-1):
    if not '#' in mx[i][0]:
        del mx[i]
l = []
for i in range(w):
    for j in range(len(mx)):
        if mx[j][0][i]=='#':
            break
        if j==len(mx)-1:
            l.append(i)
if l:
    for i in range(1,len(l)+1):
        for j in range(len(mx)):
            if l[-i]==len(mx[j][0])-1:
                mx[j][0]=mx[j][0][:l[-i]]
            else:
                mx[j][0]=mx[j][0][:l[-i]]+mx[j][0][l[-i]+1:]
for m in mx:
    print(m[0])