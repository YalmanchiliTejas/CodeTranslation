H, W = map(int, input().split())

a = []
for i in range(H):
    tmp = input()
    if tmp != '.'*len(tmp):
        a.append(tmp)

b = ['' for i in range(len(a))]
for i in range(W):
    check = 0
    for j in range(len(a)):
        if a[j][i] == '#':
            check = 1
            break
    
    if check == 1:
        for j in range(len(a)):
            print()
            b[j] += a[j][i]


for i in range(len(b)):
    print(b[i])