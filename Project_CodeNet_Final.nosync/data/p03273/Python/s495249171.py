H,W = (int(i) for i in input().split())
li = []
for i in range(H):
    li.append(input())
gyou = [False for i in range(H)]
retsu = [False for i in range(W)]
for i in range(H):
    if '#' in list(li[i]):
        gyou[i] = True
        for j in range(W):
            if list(li[i])[j] == '#':
                retsu[j] = True
for i in range(H):
    l = []
    if gyou[i] == True:
        for j in range(W):
            if retsu[j] == True:
                l.append(list(li[i])[j])
    print(''.join(l))