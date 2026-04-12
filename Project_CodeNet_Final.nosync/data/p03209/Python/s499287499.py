n, x = [int(i) for i in input().split()]

b = [1]
for _ in range(n + 1):
    b.append(b[-1] * 2 + 3)
c = [1]
for _ in range(n + 1):
    c.append(c[-1] * 2 + 1)

def a(x, n):
    if x == 0:
        return 0
    if n == 0:
        return c[0]
    x-=1
    ans = 0
    if x >= b[n - 1]:
        ans += c[n - 1]
        x -= b[n - 1]
    else:
        return a(x, n - 1)
    if x == 0:
        return ans
    elif x == 1:
        return ans + 1
    else:
        ans += 1
        x -= 1
        ans += a(x, n - 1)
        return ans
    
print(a(x,n))
