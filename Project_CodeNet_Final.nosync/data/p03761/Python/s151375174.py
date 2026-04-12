n = int(input())
s = [input() for _ in range(n)]

cnt = []
for i in range(ord('a'), ord('z') + 1):
     cnt.append(min(v.count(chr(i)) for v in s))

ans = ''
for i, v in enumerate(cnt):
    ans += chr(97 + i) * v
print(ans)