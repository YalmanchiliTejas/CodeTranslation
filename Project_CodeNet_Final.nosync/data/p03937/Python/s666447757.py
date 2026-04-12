import pprint

H, W = list(map(int, input().split()))
A = []
for h in range(H):
    A.append([s for s in input()])
x, y = 0, 0
goal_x, goal_y = W - 1, H - 1
count = 0
while not (x == goal_x and y == goal_y):
    for diff_x, diff_y in [(1, 0), (0, 1), (-1, 0), (0, -1)]:
        tmp_x = x + diff_x
        tmp_y = y + diff_y
        if tmp_x < 0 or tmp_x >= W or tmp_y < 0 or tmp_y >= H:
            continue
        if A[tmp_y][tmp_x] == "#":
            if diff_x == -1 or diff_y == -1:
                print("Impossible")
                exit()
            A[y][x] = "."
            x += diff_x
            y += diff_y
            # print(y, x)
            # pprint.pprint(A)
            break
    count += 1
    if (W + H - 2) < count:
        print("Impossible")
        exit()

A[goal_y][goal_x] = "."
# pprint.pprint(A)

for h in range(H):
    for w in range(W):
        if A[h][w] == "#":
            print("Impossible")
            exit()
print("Possible")
