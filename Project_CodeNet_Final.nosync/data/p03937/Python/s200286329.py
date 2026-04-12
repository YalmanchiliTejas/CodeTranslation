H, W = map(int, input().split())
A = [input() for _ in range(H)]
count = 0
for i in range(H):
    for j in range(W):
        count += "#".count(A[i][j])
if count == H + W - 1:
    print("Possible")
else:
    print("Impossible")
