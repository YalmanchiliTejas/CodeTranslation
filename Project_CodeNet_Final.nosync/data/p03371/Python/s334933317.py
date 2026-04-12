a, b, c, x, y = map(int, input().split())
key1 = min([x, y])
key2 = abs(x-y)
ans = min([a+b, 2*c]) * key1
if x > y:
    ans += min([a, 2*c]) * key2
else:
    ans += min([b, 2*c]) * key2
print(ans)