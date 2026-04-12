r, g, b = list(map(str, input().split()))
m = (r + g + b)
n = int(r + g + b)
if n % 4 == 0:
    print("YES")
else:
    print("NO")