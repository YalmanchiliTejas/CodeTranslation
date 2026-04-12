H, W = map(int, input().split())
a = []
for h in range(H):
    aw = input()
    if '#' not in aw:
        continue
    a.append(aw)

skip = []
counter = 0
for i in range(W):
    if '#' not in [x[i] for x in a]:
        skip.append(i)

for row in a:
    for i in range(len(row)):
        if i not in skip:
            print(row[i], end='')
    print()