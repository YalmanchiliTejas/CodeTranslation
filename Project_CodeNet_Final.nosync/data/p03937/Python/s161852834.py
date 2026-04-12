H, W = map(int, input().split())
a = ['.'*(W+2)]
for i in range(H):
    a.append('.'+input()+'.')
a.append('.'*(W+2))
x, y = 1, 1
d = [0, 1], [1, 0]

#右と下だけで行けるところまで行く
while True:
    #現在地を探索済みにする
    a[x] = a[x][:y] + '*' + a[x][y+1:]
    
    if [x, y] == [H, W]:
        break
    
    #右か下に進む
    for d_i in d:
        if a[x+d_i[0]][y+d_i[1]]=='#':
            x, y = x+d_i[0], y+d_i[1]
            break
    #行き止まりなら終了
    else:
        break
    
    
#探索結果を確認
end = 0
for r_i in a:
    for j in r_i:
        if j == '#':
            print('Impossible')
            end = 1
            break
    if end == 1:
        break
else:
    print('Possible')