H, W = map(int, input().split())
a = [[i for i in input()] for _ in range(H)]
a_new = []
a_new_new = []

for i in range(H):
    for j in range(W):
        if a[i][j] == '#':
            a_new.append(a[i])
            break

a_ = list(zip(*a_new))
a_H  = len(a_)
a_W  = len(a_[0])

for i in range(a_H):
    for j in range(a_W):
        if a_[i][j] == '#':
            a_new_new.append(a_[i])
            break
 
for i in list(zip(*a_new_new)):
    print(''.join(i))