H, W = map(int, input().split())
mat = [input() for _ in range(H)]

# 列から確認
ans = []
for i in range(H):
    row = mat[i]
    if all(['.' == r for r in row]):
        continue
    ans.append(row)

columns = [''.join([a[w] for a in ans]) for w in range(W)]
tmp = len(ans)
columns = [c for c in columns if '.' * tmp != c]

ans = [''.join([c[i] for c in columns]) for i in range(len(columns[0]))]
print('\n'.join(ans))
