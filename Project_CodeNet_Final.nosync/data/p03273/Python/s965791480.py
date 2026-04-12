h,w = map(int,input().split())

l = []

for i in range(h):
    l.append(list(input()))
flag = False

while not flag:
    f2=True
    for i in range(h):
        if len(set(l[i])) == 1 and l[i][0]=='.':
            l.pop(i)
            f2=False
            break
    
    h=len(l)
    w=len(l[0])

    for j in range(w):
        f3=True
        for i in range(h):
            f3 = f3 and l[i][j]=='.'
        if f3:
            for i in range(h):
                l[i].pop(j)
            f2=False
            break
    h=len(l)
    w=len(l[0])
    flag = f2

for i in range(len(l)):
    s = ''
    for j in range(len(l[0])):
        s+=l[i][j]
    print(s)
