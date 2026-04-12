H, W = map(int, input().split())
inputs = [input() for _ in range(H)]

x = 0
y = 0

counts = 0
for item in inputs:
    counts += item.count('#')

if counts != (H + W - 1):
    ans = 'Impossible'
else:
    for _ in range(H + W - 2):
        if x + 1 < W and inputs[y][x + 1] == '#':
            x += 1
        elif y + 1 < H and inputs[y + 1][x] == '#':
            y += 1
    ans = 'Possible' if y == H - 1 and x == W - 1 else 'Impossible'

print(ans)
