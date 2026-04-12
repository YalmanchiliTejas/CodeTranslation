h, w = map(int, input().split())
a = []
colrow = []

for i in range(h):
    b = list(input())
    if set(b) == {"."}:
            continue
    a.append(b)

for x in zip(*a): #各リストの1番目から順番に出力
    if set(x) == {"."}:
        continue
    colrow.append(x)

for x in zip(*colrow):
    print(*x, sep="")