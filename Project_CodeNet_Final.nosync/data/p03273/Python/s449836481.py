H, W = map(int, input().split())
a = [[c for c in input()] for _ in range(H)]

b = []
for i in range(len(a)):
    if "#" in a[i]:
        b.append(a[i])

c = [[] for _ in range(len(b))]
for j in range(W):
    if any(["#" == b[i][j] for i in range(len(b))]):
        for i in range(len(b)):
            c[i].append(b[i][j])

for line in c:
    print("".join(line))
