h, w = map(int, input().split())
count = 0
for i in range(h):
    a = input()
    for char in a:
        if char == '#':
            count += 1
print('Possible' if count == h + w - 1 else 'Impossible')
