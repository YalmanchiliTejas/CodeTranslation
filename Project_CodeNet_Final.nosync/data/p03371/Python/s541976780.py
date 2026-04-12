a, b, c, x, y = map(int, input().split())
max_count = max(x, y)
ans = 10**18

for i in range(max_count+1):
    tmp = i*2*c
    if x-i > 0:
        tmp += (x-i)*a
    if y-i > 0:
        tmp += (y-i)*b
    ans = min(ans, tmp)

print(ans)
