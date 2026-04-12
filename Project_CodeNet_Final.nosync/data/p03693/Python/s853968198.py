r, g, b = map(int, input().split())

num = 100 * r + 10 * g + b
if num % 4 == 0:
    ans = 'YES'
else:
    ans = 'NO'

print(ans)