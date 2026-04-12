# input
H,W = map(int, input().split())
a = [0 for _ in range(H)]
for i in range(H):
    a[i] = [c for c in input()]

#solve
has_black = [0 for _ in range(H)]
for i in range(H):
    if "#" in a[i]:
        has_black[i] = 1
new_a_1 = []
for i in range(H):
    if has_black[i] == 1:
        new_a_1.append(a[i])

for i in range(W):
    for j in range(len(new_a_1)):
        if new_a_1[j][i] == "#":
            break
    else:
        for j in range(len(new_a_1)):
            new_a_1[j][i] = ""

for string in new_a_1:
    print("".join(string))