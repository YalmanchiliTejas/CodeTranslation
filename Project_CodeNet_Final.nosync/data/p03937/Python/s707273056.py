h, w = map(int, input().split())
a = [input() for _ in range(h)]
now = 0
ng = 0
for i in range(h):
    # print(now)
    # 限界まで伸ばせる点を探し、それより先に#がないことを確認
    extended = 0
    if a[i][now] != "#" or "#" in a[i][:now]:
        ng = 1
        # print(i, now)
        break
    for j in range(now, w):
        if not extended:
            if a[i][j] == "#":
                now = j
            else:
                extended = 1
        else:
            if a[i][j] == "#":
                #print(i, j)
                ng = 1
                break
        if i == h - 1 and j == w - 1 and a[i][j] == ".":
            ng = 1
    if ng:
        break
if ng:
    print("Impossible")
else:
    print("Possible")
