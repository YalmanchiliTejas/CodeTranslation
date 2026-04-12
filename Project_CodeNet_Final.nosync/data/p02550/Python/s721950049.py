import sys
input = lambda: sys.stdin.readline().rstrip("\r\n")

n, x, m = map(int, input().split())
s = set([x])
l = [x]
for i in range(m):
    x = x**2 % m
    if x in s:
        start_index = l.index(x)
        break
    else:
        s.add(x)
        l.append(x)
ans = sum(l[:start_index])

q = l[start_index:]
p = (n - start_index) // len(q)
ans += sum(q) * p
ans += sum(q[:(n - p*len(q) - start_index)])
print(ans) 