n=int(input())
S=[input() for i in range(n)]
s=list(map(chr,range(97,123)))
ans=""
for i in s:
    tmp=99
    for j in S:
        tmp=min(tmp,j.count(i))
    ans+=i*tmp
print(ans)