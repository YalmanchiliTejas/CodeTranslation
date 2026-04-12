def chk_ent(r, c, arr):   
    chk_up = (arr[r-1][c] == '#') if ((r - 1) >= 0) else False
    chk_left = (arr[r][c-1] == '#') if ((c - 1) >= 0) else False
    
    return (chk_up, chk_left)

def chk_exit(r, c, arr):
    my_h = len(arr)
    my_w = len(arr[0])
    
    chk_down = (arr[r+1][c] == '#') if ((r + 1) < my_h) else False
    chk_right = (arr[r][c+1] == '#') if ((c + 1) < my_w) else False
    
    return (chk_down, chk_right)


h, w = map(int, input().split())
a = [list(input()) for _ in range(h)]

r = 0
c = 0
while True:
    up, left = chk_ent(r, c, a)
    if (not(up or left) and not((r == 0) and (c == 0))) or (up and left):
        flg = False
        break
    down, right = chk_exit(r, c, a)
    if not(down or right):
        if((r == (h - 1)) and (c == (w - 1))):
            flg = True
            break
        else:
            flg = False
            break
    elif (down and right):
        flg = False
        break
    elif right:
        c += 1
    elif down:
        r += 1
print('Possible' if flg else 'Impossible')