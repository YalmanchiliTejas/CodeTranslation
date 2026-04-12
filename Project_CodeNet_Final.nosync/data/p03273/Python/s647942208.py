H, W = map(int, input().split())
lst = []
for _ in range(H):
    s = input()
    if s.find('#') >= 0:
        lst.append(s)

lst2 = []
for w in range(W):
    skip = True
    for h in range(len(lst)):
        if lst[h][w] == '#':
            skip = False
            break
    lst2.append(skip)

for x in lst:
    for idx, y in enumerate(x):
        if not lst2[idx]:
            print(y, end='')
    print()