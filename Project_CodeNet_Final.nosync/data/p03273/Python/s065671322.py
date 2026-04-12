H, W = map(int, input().split(' '))

rows = [input() for _ in range(H)]
rows = [row for row in rows if '#' in row]
cols = list(zip(*rows))
cols = [col for col in cols if '#' in col]
rows = list(zip(*cols))

for row in rows:
    print(''.join(row))
