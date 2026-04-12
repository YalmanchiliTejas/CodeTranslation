from sys import stdin
N=int(stdin.readline().rstrip())
S=(stdin.readline().rstrip())
K=int(stdin.readline().rstrip())
s=S[K-1]

ans=""
for i in list(S):
    if i != s:
        ans+="*"
    else:
        ans+=i
print(ans)