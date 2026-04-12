L = int(input())
s = input()
t = input()
if not s+t <= t+s:
    s, t = t, s
ls = len(s); lt = len(t)
for i in range(L // ls, -1, -1):
    if (L - ls*i) % lt == 0:
        ans = s * i + t * ((L - ls*i) // lt)
        break
print(ans)