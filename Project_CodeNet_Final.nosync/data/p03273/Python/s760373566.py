H, W = map(int, input().split())
matrix = []
ans = []
for i in range(H):
    h = list(input())
    if "#" in h:
        matrix.append(h)
for j in range(W):
    w = [w_[j] for w_ in matrix]
    if "#" in w:
        ans.append(w)
for k in range(len(ans[0])):
    print("".join([r[k] for r in ans]))