#移動できる回数が限られている。
#具体的には、#の数がh+w個ピッタリじゃなくてはならない
h, w = map(int, input().split())
grid = []
sharp_count = 0
for i in range(h):
    grid.append(list(input()))
    sharp_count += grid[i].count('#')
if sharp_count != h+w-1:
    print("Impossible")
else:
    print("Possible")
