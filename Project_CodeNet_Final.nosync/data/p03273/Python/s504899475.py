(H, W) = list(map(int, input().split()))

a = list()
for height in range(H):
    line = input()
    if line == '.' * W:
        pass
    else:
        a.append(list(line))

# 転置して空白行を削除
a = [list(x) for x in zip(*a)]
a_trim = list()
for a_row in a:
    if ''.join(a_row) == '.' * len(a_row):
        pass
    else:
        a_trim.append(a_row)

a = [list(x) for x in zip(*a_trim)]  # 転置

for row in a:
    print(''.join(row))
