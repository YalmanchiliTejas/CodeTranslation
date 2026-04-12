H, W = map(int, input().split())

a = [list(input()) for i in range(H)]

WHITE = '.'
BLACK = '#'

new_a = []

for i in range(H):
    if BLACK in a[i]:
        new_a.append(a[i])

new_H = len(new_a)
new_W = len(new_a[0])
new_a2 = [[] for i in range(new_H)]

for j in range(new_W):

    has_black = False

    for i in range(new_H):
        if new_a[i][j] == BLACK:
            has_black = True

    if has_black:
        for i in range(new_H):
            new_a2[i].append(new_a[i][j])

for row in new_a2:
    for data in row:
        print(data, end='')
    print('')

