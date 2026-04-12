h, w = map(int, input().split())
grid = []
for i in range(h):
    a = input()
    x = [j for j in a]
    grid.append(x)
grid_2 = []
for j in grid:
    if '#' in j:
        grid_2.append(j)

rotate = []
for i in range(w):
    r = [row[i] for row in grid_2]
    rotate.append(r)

rotate_2 = []
for j in rotate:
    if "#" in j:
        rotate_2.append(j)

re_rorate = []
z = len(rotate_2[0])
for i in range(z):
    r_r = [row[i] for row in rotate_2]
    re_rorate.append(r_r)

for i in range(z):
    y = re_rorate[i]
    j ="".join(y)    
    print(j)