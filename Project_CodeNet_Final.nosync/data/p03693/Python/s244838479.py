r, g, b = input().split()
rgb = int(r + g + b)
ans = 'NO'
if rgb % 4 == 0:
  ans = 'YES'
print(ans)