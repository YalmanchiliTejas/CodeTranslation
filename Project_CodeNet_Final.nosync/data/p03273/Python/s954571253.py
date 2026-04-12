H, W = map(int, input().split())
A = [input() for _ in range(H)]
B = [A[h] for h in range(H) if '#' in A[h]]

rem = []
for w in range(W):
    col = [B[i][w] for i in range(len(B))]
    if '#' not in col:
        rem.append(w)

for h in range(len(B)):
    for w in range(W):
        if w not in rem:
            print(B[h][w], end="")
    print()