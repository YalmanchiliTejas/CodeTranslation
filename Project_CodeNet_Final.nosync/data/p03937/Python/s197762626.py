h, w = map(int, input().split())
tizu = [list(input()) for _ in range(h)]
pos = 1
for row in tizu:
    pos -= 1
    for i, index in enumerate(row):
        if i == pos:
            if index == "#":
                pos += 1
        else:
            if index == "#":
                print("Impossible")
                exit()
print("Possible")