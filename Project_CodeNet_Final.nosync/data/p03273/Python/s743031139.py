h,w = map(int,input().split())
a=[]
for i in range(h):
    b = input()
    f = False
    for j in range(len(b)):
        if b[j] == '#':
            f = True
    if f:
        a.append(list(b))

f = True
cnt = 0
for i in range(len(a[0])):
    for j in range(len(a)):
        if(a[j][i-cnt] == '#'):
            f = False
    if f:
        for j in range(len(a)):
            del a[j][i-cnt]
        cnt += 1
    f = True

for i in range(len(a)):
    for j in range(len(a[0])):
        print(a[i][j],end="")
    print()