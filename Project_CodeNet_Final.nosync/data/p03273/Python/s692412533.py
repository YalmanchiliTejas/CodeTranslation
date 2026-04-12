h,w = map(int, input().split())
mat = [list(input()) for _ in range(h)]

nrow = len(mat[0])
row_checked_mat = [row for row in mat if not row.count('.') == nrow]

ncol = len(row_checked_mat)
col_checked_mat = [col for col in zip(*row_checked_mat) if not col.count('.') == ncol]

for mat_i in zip(*col_checked_mat):
  print(*mat_i, sep='')