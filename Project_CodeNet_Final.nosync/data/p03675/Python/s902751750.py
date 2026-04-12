n = int(input())
s = list(map(int, input().split()))
t = []
if n % 2 == 0:
    for i in range(n // 2):
        t.append(s[-(i * 2 + 1)])
    for i in range(n // 2):
        t.append(s[i * 2])
else:
    for i in range(n // 2 + 1):
        t.append(s[-(i * 2 + 1)])
    for i in range(n // 2):
        t.append(s[i * 2 + 1])
r = ''
for n in t:
    r += str(n) + ' '
print(r)
