a, b, c, x, y = map(int, input().split())
ans = 0
cnt = 0
while x > cnt and y > cnt:
    ans += min(a+b, c*2)
    cnt += 1

if x > cnt:
    while x > cnt:
        ans += min(a, c*2)
        cnt += 1
else:
    while y > cnt:
        ans += min(b, c*2)
        cnt += 1
print(ans)