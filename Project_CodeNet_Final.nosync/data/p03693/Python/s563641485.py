r, g, b = map(str, input().split())
ans = r+g+b

if int(ans)%4 == 0:
    print('YES')

else:
    print('NO')