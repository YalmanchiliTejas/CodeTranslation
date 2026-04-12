N=int(input())
S=input()
K=int(input())

onaji=S[K-1]
ans=""
for i in range(N):
    if S[i]==onaji:
        ans+=onaji
    else:
        ans+="*"
print(ans)