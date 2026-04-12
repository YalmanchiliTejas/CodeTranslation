h,w = map(int, input().split())

A = [input() for _ in range(h)]

flag = True

#初期位置
x,y=0,0
for _ in range(h+w-2):
    #枠内にいることと現在位置の右隣が'#'であることを確認する
    if x+1 < h and A[x+1][y] == '#':
        #進む
        x += 1
        continue
    #枠内にいることと現在位置の直下が'#'であることを確認する
    if y+1 < w and A[x][y+1] == '#':
        #進む
        y += 1
        continue
    #一度でも上に引っかからなかったら
    flag = False
    break

flag = flag and (sum(x.count('#') for x in A) == h+w-1)
ans = 'Possible' if flag else 'Impossible'
print(ans)