H, W = map(int, input().split())
box = []
for i in range(H):
    A = input()
    if not "#" in A:
        continue
    box.append(A)
box_t = []
for i in range(W):
    X = ""
    for j in range(len(box)):
        X += box[j][i]
    if not "#" in X:
        continue
    box_t.append(X)
for i in range(len(box_t[0])):
    for j in range(len(box_t)):
        print(box_t[j][i], end="")
    if i == len(box_t[0]) - 1:
        break
    print()