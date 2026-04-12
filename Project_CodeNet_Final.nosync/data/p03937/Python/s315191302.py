H, W = map(int, input().split())

array = []
for _ in range(H):
    array.append(list(input()))

possible = True
prev_min_hash = W

for h in range(H-1, -1, -1):
    max_hash = 0
    for w in range(W):
        if array[h][w] == "#":
            max_hash = w

    if max_hash > prev_min_hash:
        possible = False
        break

    for w in range(W-1, -1, -1):
        if array[h][w] == "#":
            prev_min_hash = w

if possible:
    print('Possible')
else:
    print('Impossible')