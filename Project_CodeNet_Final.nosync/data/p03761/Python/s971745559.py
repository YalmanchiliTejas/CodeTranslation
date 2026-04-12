n=int(input())
S=[input() for i in range(n)]
s=set(S[0])
for i in range(1,n):
    s&=set(S[i])
ans=""
for i in sorted(s):
    tmp=99
    for j in S:
        tmp=min(tmp,j.count(i))
    ans+=i*tmp
print(ans)