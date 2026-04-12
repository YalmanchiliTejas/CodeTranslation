import numpy as np

h, w = map(int, input().strip().split())
table = np.array([list(input().strip()) for _ in range(h)])


def compress_row(table):
    new_table = []
    compressed = False
    for row in table:
        if all([c == '.' for c in row]):
            compressed = True
            continue
        else:
            new_table.append(row)

    return compressed, np.array(new_table)


def compress_col(table):
    tr_table = table.T
    compressed, new_tr_table = compress_row(tr_table)
    return compressed, new_tr_table.T


while True:
    row_compressed, table = compress_row(table)
    col_compressed, table = compress_col(table)

    if (not row_compressed) and (not col_compressed):
        break

for row in table:
    print(''.join(row))
