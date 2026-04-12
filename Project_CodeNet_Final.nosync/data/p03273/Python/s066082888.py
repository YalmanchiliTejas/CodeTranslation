H, W = map(int,input().split())

a = [list(input()) for i in range(H)]
b = ['.']*W

while b in a:
    a.remove(b)

for j in range(W):
    flag = 0
    for i in a:
        if i[j] == '#':
            flag = 1
            break
    if flag == 0:
        for i in a:
            i[j] = ''
    
for i in a:
    print(''.join(i))