import sys

n, x, m = map(int, input().split())

if x == 0:
    print(0)
    sys.exit()

l = [x]
s = {x}
prev = x

for i in range(1, m):
    next = prev ** 2
    next = next % m
    if next in s:
        break
    s.add(next)
    l.append(next)
    prev = next
start = l.index(next)
length = i - start

ans = 0
if n < start + length:
    ans += sum(l[:n])
else:
    ans += sum(l[:start])
    ans += sum(l[start:]) * ((n - start) // length)
    ans += sum(l[start:(start + ((n - start) % length))])

print(ans)
