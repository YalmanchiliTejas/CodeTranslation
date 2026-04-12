h, w = map(int, input().split())
ma = [list(str(input())) for _ in range(h)]
row = [0] * h
column = [0] * w 

for i in range(h):
    if ma[i] == ['.'] * w:
      row[i] = 1

j = 0
while j < w:
    count = 0
    for i in range(h):
        if ma[i][j] == '.':
            count += 1
        if count == h:
            column[j] = 1
    j += 1

for i in range(h):
    if row[i] == 1:
        for j in range(w):
            ma[i][j] = ''

for j in range(w):
    if column[j] == 1:
        for i in range(h):
            ma[i][j] = ''

for i in range(h):
    if ma[i].count('') == len(ma[i]): 
        continue
    else:
        print(''.join(ma[i]))