x, y, z = map(int, input().split())
ans = x * 100 + y * 10 + z
if ans % 4 == 0:
    print("YES")
else:
    print("NO")
