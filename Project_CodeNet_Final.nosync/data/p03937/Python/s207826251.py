H, W = map(int, input().split())
A = [[] for i in range(H)]
check1 = 0
check2 = 1
now = [0, 0]
flag = True

for i in range(H):
    A[i] = input()
    check1 += A[i].count('#')
    
for iii in range(30000):
    lim = 0
    for dy, dx in [1, 0], [0, 1]:
        lim += 1
        if now[0] + dy <= H-1 and now[1] + dx <= W-1:
            if A[now[0] + dy][now[1] + dx] == '#':
                check2 += 1
                now[0] += dy
                now[1] += dx
                break
                
        if lim == 2:
            break
                
if check2 == check1:
    print('Possible')
else:
    print('Impossible')