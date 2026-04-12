r, g, b = map(int, input().split())
num = 100 * r + 10 * g + b
ans = 'NO'
if num % 4 == 0:
    ans = 'YES'
print(ans)