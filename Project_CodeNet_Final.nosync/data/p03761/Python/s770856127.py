n = int(input())
a = ord('a')

count = [0]*26
def p():
    return list(map(lambda x: ord(x) - a, list(input())))
s = p()
for s_ in s:
    count[s_] += 1
for _ in range(n-1):
    c = [0]*26
    s = p()
    for s_ in s:
        c[s_] += 1
    for i in range(26):
        count[i] = min(count[i], c[i])
ans = ""
for i in range(26):
    ans += chr(i+a)*count[i]
print(ans)
