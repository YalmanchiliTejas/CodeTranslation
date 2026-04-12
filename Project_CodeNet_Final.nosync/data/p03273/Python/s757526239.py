h,w = map(int, raw_input().split())
mat = [list(raw_input()) for _ in range(h)]
rows = set([i for i in range(len(mat)) if '#' in mat[i]])

cols = set([i for i in range(len(mat[0])) if '#' in [mat[j][i] for j in range(len(mat))]])

mat = [mat[i] for i in range(len(mat)) if i in rows]


mat = [[mat[i][j] for j in range(len(mat[0])) if j in cols] for i in range(len(mat))]

for l in mat:
	print ''.join(l)
