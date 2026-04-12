
r,g,b = map(int,input().split())

ans = str(r) + str(g) + str(b)
ans = int(ans)

if ans % 4 == 0:
    print("YES")
else:
    print("NO")
