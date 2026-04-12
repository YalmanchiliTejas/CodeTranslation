x, y, z = map(int,input().split())
n = y + 2 * z
ans = 0
for i in range(0,100000):
    n += y + z
    ans += 1
    if n > x:
        print(ans)
        break
      