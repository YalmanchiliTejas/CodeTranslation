h, w = map(int, input().split())
As = [list(input()) for i in range(h)]

x,y = 0,0

ans = "Possible"

while True:
    cnt = 0
    tmpX,tmpY = x,y
    # 上か左が"#" -> error
    if (x > 0 and As[y][x-1] == "#") or (y > 0 and As[y-1][x] == "#"):
        ans = "Impossible"
        break
    
    # 右も下も"#" -> error
    if x < w - 1 and As[y][x+1] == "#" and y < h - 1 and As[y+1][x] == "#":
        ans = "Impossible"
        break
    
    # 右に移動
    if x < w - 1 and As[y][x+1] == "#":
        As[y][x] = "."
        x += 1
    # 左に移動
    if y < h - 1 and As[y+1][x] == "#":
        As[y][x] = "."
        y += 1
        
    # 右下に到着
    if x == w - 1 and y == h - 1:
        As[y][x] = "."
        break

    # 移動していない
    if x == tmpX and y == tmpY:
        ans = "Impossible"
        break
        
for A in As:
    if "#" in A:
        ans = "Impossible"

print(ans)