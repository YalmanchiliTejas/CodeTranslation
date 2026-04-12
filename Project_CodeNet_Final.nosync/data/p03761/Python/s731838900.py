n = int(input())
S = [input() for i in range(n)]
ans = ''
num = []
for spell in range(26):
    for s in S:
        tmp = chr(97+spell)
        num.append(s.count(tmp))
    for i in range(min(num)):
        ans = ans + tmp
    num = []

print(ans)