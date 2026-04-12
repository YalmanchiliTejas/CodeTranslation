n=int(input())
S=str(input())
K=int(input())
ans=''
sk=S[K-1]

for i in range(n):
    if S[i]!=sk:
        ans += '*'
    else:
        ans += sk

print(ans)
