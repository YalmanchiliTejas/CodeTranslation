h, w = map(int, input().split())
vec = []

line = []
for i in range(h):
    vec.append(input())
    if '#' in vec[i]:
        line.append(i)

row = []
for i in range(w):
    for j in range(h):
        if vec[j][i] == '#':
            row.append(i)
            break

for i in line:
    for j in row:
        print(vec[i][j], end='')
    
    print()