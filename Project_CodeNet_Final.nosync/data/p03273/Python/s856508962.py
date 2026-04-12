H, W = list(map(int, input().split()))
a = []
h = []
w = []
aa = ''

for i in range(H):
    a_ = input()
    aa += a_
    a.append(a_)
    if '#' in a_:
        h.append(i)

for i in range(W):
    if '#' in aa[i::W]:
        w.append(i)
        
for i in range(H):
    if i not in h:
        continue
    flag = False
    for l in range(W):
        if l in w:
            print(a[i][l], end='')
            flag = True
    if flag == True:
        print('')
