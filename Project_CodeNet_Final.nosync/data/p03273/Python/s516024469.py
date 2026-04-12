H,W = map(int, input().split())
map =[]
for _ in range(H):
     a = list(input())
     map.append([int(x !='.') for x in a ])
memo = []
for i in range(H):
    if sum(map[i]) == 0:
        memo.append(i)
while memo:
    del map[memo[-1]]
    del memo[-1]
    H -= 1
for j in range(W):
    color = [map[x][j] for x in range(H)]
    if sum(color) == 0:
        memo.append(j)
while memo:
    for k in range(H):
        del map[k][memo[-1]]
    del memo[-1]
    W = -1
for j in map:
    a = ["." if ab == 0 else "#" for ab in j]
    print("".join(a))