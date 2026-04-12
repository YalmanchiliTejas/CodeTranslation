h ,w = map(int, input().split())
board = [list(input()) for tate in range(h)]
now = 0
flag = False
for i in board:
    direction = i.count("#")
    if (flag != True):
        now = direction 
        flag = True
    else:
        if(direction == 1):
            continue
        else:
            now  = now + direction - 1

if (now == w):
    print("Possible")
else:
    print("Impossible")