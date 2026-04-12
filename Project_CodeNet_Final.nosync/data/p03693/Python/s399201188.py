r, g, b = input().split()

if int(r + g + b) % 4 == 0:
    ans = "YES"
else:
    ans = "NO"

print(ans)
