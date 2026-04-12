h, w = map(int, input().split())
area = [[] for i in range(h)]

for i in range(h):
    area[i] = input()
num = 0

for i in range(h):
    for j in range(w):
        if area[i][j] == '#' and j < num:
            print('Impossible')
            exit()
        elif area[i][j] == '#':
            num = j

print('Possible')
