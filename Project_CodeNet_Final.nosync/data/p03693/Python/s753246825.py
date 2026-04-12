r, g, b = list(map(int, input().split(' ')))

num = 100 * r + 10 * g + b
if num % 4 == 0:
    print('YES')
else:
    print("NO")
