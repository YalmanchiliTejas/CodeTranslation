h,w = map(int,input().split())
block = [input() for _ in range(h)]
ok = [[False] * w for _ in range(h)]

for y in range(h):
    for x in range(w):
        if block[y][x] == '.':
            #print(y,x)
            nowy = 0
            nowx = 0
            flag = True
            while nowy < h:
                if block[nowy][x] == '.':
                    nowy += 1
                else:
                    flag = False
                    break
            if flag:
                for y_ in range(h):
                    ok[y_][x] = True
            flag = True
            while nowx < w:
                #print(nowx)
                if block[y][nowx] == '.':
                    nowx += 1
                else:
                    flag = False
                    break
            if flag:
                for x_ in range(w):
                    ok[y][x_] = True
ans = []
for y in range(h):
    a = ""
    for x in range(w):
        if ok[y][x] != True:
            a += block[y][x]
    if len(a) != 0:
        ans.append(a)
print(*ans,sep='\n')
