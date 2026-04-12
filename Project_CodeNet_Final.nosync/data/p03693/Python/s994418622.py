r, g, b = map(str, input().split())
ans = r + g + b
ans = int(ans)
if ans % 4 == 0:
    print("YES")
else:
    print("NO")
