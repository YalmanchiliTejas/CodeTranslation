h,w= map(int,input().split())
# 二重配列
arr = [list(input()) for i in range(h)]

y = len(arr[0])
x = len(arr)

arr2 = [[0 for i in range(y)] for j in range(x)]

for i in range(0,x):
    if arr[i].count('#')!=0:
        for j in range(0,y):
            arr2[i][j]+=1

for j in range(0,y):
    f =[False]
    for i in range(0,x):
        if arr[i][j]=='#':
            f[0]=True
            break
    if f[0]==True:
        for i in range(0,x):
            arr2[i][j]+=1

for i in range(0,x):
    j = 0
    while((arr2[i].count(1)!=0)or(arr2[i].count(0)!=0)):
        if arr2[i][j]<2:
            del(arr[i][j])
            del(arr2[i][j])
            j -=1
        j += 1

for i in range(0,x):
    if len(arr[i])==0:
        continue
    print("".join(arr[i]))
