H, W = map(int, input().split())

A = []
for _ in range(H):
    A.append(list(input()))

cnt = 0
for aa in A:
    for aaa in aa:
        if aaa == '#':
            cnt += 1

if cnt == H + W - 1:
    print("Possible")
else:
    print("Impossible")
