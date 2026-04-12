r, b, g = map(int, input().split())

ans = 100*r + b*10 + g
if ans % 4 == 0:
    print("YES")
else:
    print("NO")