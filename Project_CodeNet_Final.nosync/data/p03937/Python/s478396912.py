H, W = map(int, input().split())
A = [list(input()) for i in range(H)]


def enclose_field(field, outline="#"):
    """
    迷路等の外周をoutlineで埋めることで、IndexErrorを回避できます。
    [0, 0] → [1, 1]、[H-1, W-1] → [H, W]となります。
    """
    for i in range(len(field)):
        field[i] = [outline] + field[i] + [outline]
    field.append([outline] * (len(field[0])))
    field.insert(0, [outline] * (len(field[0])))
    return field


A = enclose_field(A, outline=".")
i = j = 1
while True:
    if A[i+1][j] == "#":
        A[i][j] = "."
        i += 1
        continue

    if A[i][j+1] == "#":
        A[i][j] = "."
        j += 1
        continue

    if i==H and j == W:
        A[i][j] = "."
        break

    print("Impossible")
    exit()

for a in A:
    if "#" in a:
        print("Impossible")
        break
else:
    print("Possible")