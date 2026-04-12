n = int(input())
l_s = [input() for i in range(n)]
set_char = set(l_s[0])
for s in l_s:
    set_char &= set(s)
ans = ''
for c in sorted(set_char):
    num = 50
    for s in l_s:
        num = min(num, s.count(c))
    ans += c * num
print(ans)
