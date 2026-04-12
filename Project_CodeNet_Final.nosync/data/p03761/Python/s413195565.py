from string import ascii_lowercase
n = int(input())
s = [sorted(list(input())) for _ in range(n)]
ans = ''
for c in ascii_lowercase:
    cnt = float('inf')
    for i in s:
        cnt = min(cnt, i.count(c))
    ans += c * cnt
print(ans)