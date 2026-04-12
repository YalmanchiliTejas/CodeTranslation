n, x, m = map(int, input().split())
s = set([x])
t = [x]
p = 1
for i in range(n):
    x = x * x % m
    if x in s:
        break
    else:
        s.add(x)
        t.append(x)
    p += 1
if p == n:
    print(sum(s))
    exit()

q = t.index(x)
l = p - q
b = sum(t[q:p])
ans = sum(t[:q])
n -= q
ans += n // l * b + sum(t[q:q + n % l])
print(ans)
