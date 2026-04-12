H, W = map(int, input().split())
inputs = [input() for _ in range(H)]

y = 0
x = 0

goal_y = H - 1
goal_x = W - 1

counts = 0
for item in inputs:
    counts += item.count('#')

if counts != (H + W - 1):
    print('Impossible')
else:
    for _ in range(H + W - 2):
        if x + 1 < W and inputs[y][x + 1] == '#':
            x += 1
        elif y + 1 < H and inputs[y + 1][x] == '#':
            y += 1
    print('Possible' if y == goal_y and x == goal_x else 'Impossible')