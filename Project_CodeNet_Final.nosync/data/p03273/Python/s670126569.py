h, w = map(int, input().split())
grid = []

def method(grid, cnt, i):
    if cnt == len(grid) - 1 and grid[cnt][i] == '.':
        w_list.append(i)
    elif cnt < len(grid) - 1 and grid[cnt][i] == '.':
        method(grid, cnt + 1, i)
    else:
        False


for i in range(h):
    n = list(input())
    if n.count('.') == len(n):
        pass
    else:
        grid.append(n)

w_list = []
cnt = 0
for i in range(w):
    # ここで最初の値が。なら、次の配列も見に行くアルゴリズムをつくる
    # [
    # [000], ここで最初は０なので、下の配列も見に行く。これを。があるだけ繰り返す
    # [010],
    # [010],
    # [010]
    # ]
    method(grid, cnt, i)

w_list.reverse()

for n in w_list:
    for i in grid:
        i.pop(n)


for i in grid:
    print(''.join(i))
