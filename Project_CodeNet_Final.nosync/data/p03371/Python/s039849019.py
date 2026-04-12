a, b, c, x, y = map(int, input().split())
c2 = min(c * 2, a + b)
a = min(a, c * 2)
b = min(b, c * 2)
ans = 0

#buy set of A,B
nab = min(x, y)
ans += nab*c2
x -= nab
y -= nab


#buy remainder
ans += x * a
ans += y * b
print(ans)