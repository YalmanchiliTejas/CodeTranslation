H,W = map(int, input().split())
A = [list(input()) for _ in range(H)]

R = set()
C = set(list(range(W)))
for i in range(H):
    if not "#" in A[i]:
        R.add(i)
        continue
    tmp = set()
    for j in range(W):
        if A[i][j] == ".":
            tmp.add(j)
    C &= tmp

ans = []
for i in range(H):
    if i in R:
        continue
    tmp = []
    for j in range(W):
        if j in C:
            continue
        tmp.append(A[i][j])
    ans.append(tmp)

for a in ans:
    print(*a,sep="")