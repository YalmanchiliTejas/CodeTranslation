n=int(input())
s=[0 for i in range(n)]
alp_count=[51 for i in range(26)]

ans=""

for i in range(n):
    s[i]=input()
    for j in range(26):
        alp_count[j]=min(alp_count[j], s[i].count(chr(97+j)))

for i in range(26):
    ans=ans+alp_count[i]*(chr(97+i))

print(ans)