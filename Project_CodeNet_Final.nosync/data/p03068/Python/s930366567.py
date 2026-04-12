n=int(input())
s=input()
k=int(input())
S=list(s)
for i in range(n):
    if S[i]!=S[k-1]:
        S[i]='*'
ans=''.join(S)
print(ans)
