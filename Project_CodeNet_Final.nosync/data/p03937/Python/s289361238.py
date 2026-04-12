H, W = map(int, input().split())

A = [input() for _ in range(H)]
length = sum([a.count('#') for a in A])

print('Possible' if length == H + W - 1 else 'Impossible')
