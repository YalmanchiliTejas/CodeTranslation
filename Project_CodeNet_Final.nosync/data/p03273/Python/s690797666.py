H, W = input().split(" ")
H = int(H)
W = int(W)
table = []
for i in range(H):
    table.append(list(input()))

i = 0
while i < H:
    if '#' not in table[i]:
        del table[i]
        H -= 1
    else:
        i = i + 1

table_t = [list(x) for x in zip(*table)]

i = 0
while i < W:
    if '#' not in table_t[i]:
        del table_t[i]
        W -= 1
    else:
        i = i + 1

table = [list(x) for x in zip(*table_t)]

for i in range(H):
    print("".join(table[i]))