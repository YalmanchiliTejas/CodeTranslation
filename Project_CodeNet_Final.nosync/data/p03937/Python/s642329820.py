H, W = map(int, input().split())
a = [list(input()) for _ in range(H)]

x = 0
y = 0
ans = 'Possible'
a[0][0] = '.'
while True:
    if y < W - 1 and a[x][y + 1] == '#':
        y += 1
        a[x][y] = '.'
        continue
    elif x < H - 1 and a[x + 1][y] == '#':
        x += 1
        a[x][y] = '.'
        continue
    break

for i in range(H):
    if a[i].count('#') != 0:
        ans = 'Impossible'
        break
print(ans)