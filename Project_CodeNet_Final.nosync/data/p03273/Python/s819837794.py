def del_row(lines):
    if not lines:
        return
    erasable = []
    for idx, line in enumerate(lines):
        if all([c == '.' for c in line]):
            erasable.append(idx)
    for idx in erasable[::-1]:
        del lines[idx]


def del_col(lines):
    if not lines:
        return
    erasable = []
    for idx in range(len(lines[0])):
        col = [lines[i][idx] for i in range(len(lines))]
        if all([c == '.' for c in col]):
            erasable.append(idx)
    for idx in erasable[::-1]:
        for i in range(len(lines)):
            del lines[i][idx]


lines = []
H, W = [int(x) for x in input().split()]
for i in range(H):
    lines.append(list(input()))

del_row(lines)
del_col(lines)
for line in lines:
    print(''.join(line))
