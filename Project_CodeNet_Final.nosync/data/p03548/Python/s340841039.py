a , b , c = map(int, input().split())
m = a % (b+c)
ans = a // (b+c)
if m >= c:
    print(ans)
else:
    print(ans-1)
