H,W = [int(hoge) for hoge in input().split()]
A = [input() for j in range(H)]
Row = [r for r in range(H) if all([m=="." for m in A[r]]) ]
Col = [c for c in range(W) if all([A[r][c]=="." for r in range(H)])]
print(*["".join([A[h][w]for w in range(W) if w not in Col]) for h in range(H) if h not in Row],sep="\n")