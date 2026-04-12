r, g, b = map(int, input().split())
N = 100 * r + 10 * g + b
ans = 'YES' if N % 4 == 0 else 'NO'
print(ans)
