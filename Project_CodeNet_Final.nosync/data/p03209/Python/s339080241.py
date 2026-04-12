N,X = map(int,input().split())

s = [1]
p = [1]
for i in range(N):
    s.append(s[-1]*2 + 3)
    p.append(p[-1]*2 + 1)

ans = 0
for i in reversed(range(N)):
    if i > 0:
        if X == s[i]+2:
            ans += p[i]+1
            break
        elif X < s[i]+2:
            X -= 1
        else:
            X -= (s[i]+2)
            ans += p[i]+1
    else:
        ans += max(0,min(3, X-1))
print(ans)