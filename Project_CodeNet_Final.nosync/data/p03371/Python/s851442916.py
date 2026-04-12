a, b, c, x, y = map(int, input().split())

ans = 10**9
for i in range(10**5+1):
    tmp = 2*c*i + max((x-i), 0)*a + max((y-i), 0)*b
    if x < i and y < i:
            break
    ans = min(ans, tmp)
print(ans)