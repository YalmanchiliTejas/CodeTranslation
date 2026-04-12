a, b, c, x, y = map(int, input().split())
 
ans = float('inf')
for i in range(max(x, y)+1):
    p = 2*c*i + max(0, (x-i))*a + max(0, (y-i))*b  #; print(i, p)
    ans = min(p, ans)

print(ans)
