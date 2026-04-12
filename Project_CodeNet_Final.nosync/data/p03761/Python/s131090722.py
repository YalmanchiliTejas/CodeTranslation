from collections import Counter 
n=int(input())
S=[Counter(input()) for _ in range(n)]
s=S[0]
for i in range(n):
    for k,v in s.items():
        s[k]=min(S[i][k],s[k])
s=sorted(s.items())
ans=''
for k,v in s:
    ans+=k*v
print(ans)