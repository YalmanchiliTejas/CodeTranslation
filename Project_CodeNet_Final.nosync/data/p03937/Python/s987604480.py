h,w = map(int,input().split())
ma = []
count = 0
for _ in range(h):
    tmp_li = list(input())
    for t in tmp_li:
        if t == '#':
            count += 1
    ma.append(tmp_li)
if count != w+h-1:
    print('Impossible')
    exit()
if ma[0][0]!= '#':
    print('Impossible')
    exit()

li = [[0,0]]
def che(lis):
    lll = lis.pop(0)
    x = lll[0]
    y = lll[1]
    tmp = []
    if x+1 < w:
        #print(x+1,y,w,h,ma)
        if ma[y][x+1] == '#':
            tmp.append([x+1,y])
        if x+1 == w -1 and y == h -1:
            print('Possible')
            exit()
    if y+1 < h:
        if ma[y+1][x] == '#':
            tmp.append([x,y+1])
        if x == w -1 and y+1 == h -1:
            print('Possible')
            exit()
    if len(tmp) == 0:
        print('Impossible')
        exit()
    else:
        lis += tmp
    tmp = []
    #print(lis)
while len(li)>0:
    che(li)