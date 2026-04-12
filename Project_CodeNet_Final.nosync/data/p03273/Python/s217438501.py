h, w = map(int, input().split())
A = []
for i in range(h):
    s = input()
    if s != "." * w:
        A.append(s)

h = len(A)
white_col_index = []
for j in range(w):
    s = "".join([A[i][j] for i in range(h)])
    if s == "." * h:
        white_col_index.append(j)

output_col_index = sorted(list(set(range(w)) - set(white_col_index)))
for i in range(h):
    print("".join(A[i][j] for j in output_col_index))