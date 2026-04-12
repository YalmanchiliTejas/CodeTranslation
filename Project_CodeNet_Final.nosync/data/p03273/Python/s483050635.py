H, W = map(int, input().split())
a=[]
for _ in range(H):
    a.append(input())

delete_y=[]
for y in range(H):
    count=0
    for x in range(W):
        if a[y][x]=='.':
            count+=1
    if count==W:
        delete_y.append(y)

delete_x=[]
for x in range(W):
    count=0
    for y in range(H):
        if a[y][x]=='.':
            count+=1
    if count==H:
        delete_x.append(x)
#print(delete_x, delete_y)

for y in range(H):
    if y not in delete_y:
        row=''
        for x in range(W):
            if x not in delete_x:
                row+=(a[y][x])
        print(row)
