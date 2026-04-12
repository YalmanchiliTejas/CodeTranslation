def is_space(iterable):
    return all(map(lambda x: x == ".", iterable))


H, W = map(int, input().split())
A = [list(input()) for _ in range(H)]

remove_row_idx = []
for idx, row in enumerate(A):
    if is_space(row):
        remove_row_idx.append(idx)
# print(remove_row_idx)
for count, idx in enumerate(remove_row_idx):
    del A[idx - count]

remove_column_idx = []
for i in range(W):
    column = [r[i] for r in A]
    if is_space(column):
        remove_column_idx.append(i)

for count, idx in enumerate(remove_column_idx):
    for row in A:
        del row[idx - count]

for row in A:
    print("".join(row))
