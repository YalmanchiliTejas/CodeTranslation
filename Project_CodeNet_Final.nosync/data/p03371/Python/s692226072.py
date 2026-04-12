a, b, c, x, y = map(int, input().split())
ans = a*x + b*y
for i in range(max(x, y)+1):
    temp = 2*c*i + max(x-i, 0)*a + max(y-i, 0)*b
    ans = min(ans, temp)
print(ans)
