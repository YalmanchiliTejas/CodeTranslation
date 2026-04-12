h, w = list(map(int, input().split()))
g = []

for i in range(h):
    g.append(list(map(lambda x: 0 if x == '.' else 1, list(input()))))

changed = True
while changed:
    changed = False
    for row in g:
        if sum(row) == 0:
            g.remove(row)
            changed = True

    t = list(zip(*g))
    for column in t:
        if sum(column) == 0:
            t.remove(column)
            changed = True

    g = list(zip(*t))

result = ["".join(list(map(lambda x: "#" if x else ".", row))) for row in g]

for row in result:
    print(row)