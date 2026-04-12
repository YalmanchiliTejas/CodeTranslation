n=int(input())
s=[input() for _ in range(n)]
l='abcdefghijklmnopqrstuvwxyz'
ans=""

for i in l:
    t=10**9
    for j in range(n):
        if s[j].count(i)==0:
            break
        else:
            t=min(t,s[j].count(i))
    else:
        ans+=i*t

print(ans)
            
