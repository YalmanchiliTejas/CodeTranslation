h,w = map(int,input().split())
A = [list(input()) for i in range(h)]
White_rows = []
for i in range(h):
    if A[i] == ['.' for j in range(w)]:
        White_rows += [i]
White_rows.sort(reverse=True)
for row in White_rows:
    A.pop(row)
White_cols = []
for i in range(w):
    if all([A[j][i] == '.' for j in range(len(A))]):
        White_cols += [i]
White_cols.sort(reverse=True)
for col in White_cols:
    for j in range(len(A)):
        A[j].pop(col)
for a in A:
    print(*a,sep='')