H, W = map(int, input().split())
M = []
for i in range(H):
    L = list(input())
    if '#' in L:
        M.append(L)
Mt = list(map(list, zip(*M)))
A = []
for i in range(W):
    L = Mt[i]
    if '#' in L:
        A.append(L)
ans = list(map(list, zip(*A)))
for i in range(len(ans)):
    L = ans[i]
    print("".join(L))