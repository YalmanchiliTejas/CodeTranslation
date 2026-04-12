h, w = map(int, input().split())

a = []
for _ in range(h):
    row = list(input())
    if not all([c == '.' for c in row]):
        a.append(row)

all_whites = []
for j in range(w):
    if all([a[i][j] == '.' for i in range(len(a))]):
        all_whites.append(j)

for row in a:
    removed_row = [row[j] for j in range(w) if j not in all_whites]
    print(''.join(removed_row))
