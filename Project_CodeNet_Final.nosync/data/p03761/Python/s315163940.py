n=int(input())
s=[input() for _ in range(n)]
ans=""
for i in "abcdefghijklmnopqrstuvwxyz":
    m=99
    for j in range(n):
        t=s[j].count(i)
        m=min(m,t)
    ans+=i*m
print(ans)