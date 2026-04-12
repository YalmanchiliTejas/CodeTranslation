n = int(input())
l = [input() for _ in range(n)]
ans = ''
for i in range(ord('a'), ord('z') + 1):
    s = chr(i)
    num = float('inf')
    for j in l:
        num = min(num, j.count(s))
    ans += s * num
print(ans)