n = int(input())
s = []
for i in range(n):
    s.append(input())
alp = "abcdefghijklmnopqrstuvwxyz"
ans = ""
for a in alp:
    cnt = 1e10
    for ss in s:
        cnt = min(cnt,ss.count(a))
    for i in range(cnt):
        ans += a
print(ans)
