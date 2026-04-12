H, W = map(int, input().split())
A = []

for _ in range(H):
    row = list(input())
    if "#" in row:
        A.append(row)

for i in range(W):
    if "#" not in [a[i] for a in A]:
        for a in A:
            a[i] = None

for a in A:
    for i in range(W):
        s = a[i]
        if s != None:
            print(s, end="")
    print()
