N=int(input())
S=input()
K=int(input())

w=S[K-1]
ans=""
for i in range(N):
    if S[i]!=w: ans+="*"
    else: ans+=S[i]

print(ans)