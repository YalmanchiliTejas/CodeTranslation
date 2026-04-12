N=int(input())
S=input()
K=int(input())

ans=""
d=S[K-1]
for i in range(N):
    p = S[i] if S[i]==d else "*"
    ans +=p
print(ans)