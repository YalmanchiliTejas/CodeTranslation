a,s,k = list(input() for _ in range(3))
S = s[int(k)-1]
ans = ""
for v in s:
    if v != S: ans += "*"
    else: ans += v
print(ans)