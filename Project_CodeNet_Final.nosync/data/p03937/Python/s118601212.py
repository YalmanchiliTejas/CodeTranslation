h, w = map(int, input().split())
A = [input() for _ in range(h)]

cnt = 0
for v in A:
	cnt += v.count('#')

print('Possible') if cnt == h + w - 1 else print('Impossible')