n = int(input())
s = [input() for _ in range(n)]
ans = ''
for i in range(ord('a'), ord('z')+1):
    i = chr(i)
    m = 50
    for c in s:
        m = min(m, c.count(i))
    ans += i*m
print(ans)