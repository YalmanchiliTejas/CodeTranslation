n, x, m = map(int, input().split())
# init = x
# 二乗してあまりが x となる個数
amari = [0] * (m + 1)
for i in range(m + 1):
    y = pow(i, 2, m)
    amari[y] += 1 

visited = [0] * (m + 1)
now = x
loop = 1
while True:
    y = pow(now, 2, m)
    if visited[y] == 1:
        last = y
        break
    visited[y] += 1
    now = pow(now, 2, m)
    loop += 1

# print(visited)
# print(loop)
# print(last, 'last')

res = x

# 循環する手前まで
cnt_init = 1
now = x
while True:
    y = pow(now, 2, m)
    # print(y)
    if y == last:
        break
    res += pow(now, 2, m)
    now = pow(now, 2, m)
    cnt_init += 1

# print(loop)
loop = loop - cnt_init
# print(cnt_init)
# print(loop)

# 循環
cnt = (n - cnt_init) // loop
tmp = last # 最初足し込む
now = last
while True:
    y = pow(now, 2, m)
    if y == last:
        break
    tmp += pow(now, 2, m)
    # print('y', y)
    now = pow(now, 2, m)

res += tmp * cnt

# 残り
nokori = (n - cnt_init) % loop

if nokori == 0:
    print(res)
    exit()

now = last
res += last
for _ in range(nokori-1):
    res += pow(now, 2, m)
    now = pow(now, 2, m)

print(res)