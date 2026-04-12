rgb = input().split()
ans = "".join(rgb)
ans = int(ans)
if ans%4 == 0:
    print('YES')
else:
    print('NO')