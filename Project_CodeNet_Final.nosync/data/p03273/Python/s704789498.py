import sys

def resolve():
    H, W = map(int, input().split(" "))
    cols = [input() for i in range(H)]
    skip_cols = []
    skip_rows = []
    for i, col in enumerate(cols):
        if col.replace(".", "") == "":
            skip_cols.append(i)
    for j in range(W):
        for col in cols:
            if col[j] == "#":
                break
        else:
            skip_rows.append(j)
    for i, col in enumerate(cols):
        if i in skip_cols:
            continue
        for j, c in enumerate(col):
            if j in skip_rows:
                continue
            sys.stdout.write(c)
        sys.stdout.write("\n")
    return

if '__main__' == __name__:
    resolve()