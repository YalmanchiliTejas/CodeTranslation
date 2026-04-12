h, w = map(int, input().split())
a = []
for _ in range(h):
    a.append(input())
row = []
col = []
for i in range(h):
    for j in range(w):
        if a[i][j]=='#':
            break
    else:
        row.append(i)
for i in range(w):
    for j in range(h):
        if a[j][i]=='#':
            break
    else:
        col.append(i)
a = [[e for j, e in enumerate(r) if j not in col] for i, r in enumerate(a) if i not in row]    
for r in a:
    print(''.join(r))