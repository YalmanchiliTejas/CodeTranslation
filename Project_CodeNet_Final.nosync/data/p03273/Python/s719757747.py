H, W = map(int, input().split())
a = [[] for i in range(H)]
for i in range(H):
    line = input()
    for cell in line:
        a[i].append(cell)

for _ in range(100):
    for i, row in enumerate(a):
        if "#" not in row:
            a.pop(i)
            break

    for i, col in enumerate(zip(*a)):
            if "#" not in col:
                for j, row in enumerate(a):
                    a[j].pop(i)
                break

for row in a:
    for sign in row:
        print(sign, end="")
    print()