H, W = map(int, input().split())
A = []
for _ in range(H):
    A.append(input())

r = 0

for a in A:
    flag = False
    if '#' in a[:r]:
        print('Impossible')
        exit()
    for i in range(r, W):
        if a[i] == '#':
            if flag:
                print('Impossible')
                exit()
            r = i
        else:
            flag = True
            
print('Possible')
        