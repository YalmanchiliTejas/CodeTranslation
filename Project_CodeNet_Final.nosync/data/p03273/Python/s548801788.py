import sys

H, W = map(int, input().split())

a = [None for _ in range(H)]
for i in range(H):
    a[i] = list(input())

skipedIdx_I = set()
skipedIdx_J = set()

# print(a)

for i in range(H):
    skip = True
    for j in range(W):
        if a[i][j] == "#":
            skip = False
    if skip == True:
        skipedIdx_I.add(i)

for j in range(W):
    skip = True
    for i in range(H):
        if a[i][j] == "#":
            skip = False
    if skip == True:
        skipedIdx_J.add(j)

# print(skipedIdx_I)
# print(skipedIdx_J)

for i in range(H):
    if not i in skipedIdx_I:
        for j in range(W):
            if not j in skipedIdx_J:
                print(a[i][j], end="")
        print()

sys.exit(0)
