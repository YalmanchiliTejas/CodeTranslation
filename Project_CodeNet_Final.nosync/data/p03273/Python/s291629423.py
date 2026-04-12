h, w = map(int, input().split())
a = [''] * h

for i in range(h):
    a[i] = input()
    
row = [False] * h
cal = [False] * w

for i in range(h):
    for j in range(w):
        if a[i][j] == '#':
            row[i] = True
            cal[j] = True
            
for i in range(h):
    if row[i]:
        for j in range(w):
            if cal[j]:
                print(a[i][j], end='')
        print()