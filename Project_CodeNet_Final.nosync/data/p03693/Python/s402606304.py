r, g, b = list(input().split())
ans = 'YES' if int(r + g + b) % 4 == 0 else 'NO'
print(ans)
