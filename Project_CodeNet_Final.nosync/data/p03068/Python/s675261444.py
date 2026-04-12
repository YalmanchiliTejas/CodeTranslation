N=int(input())
S=input()
K=int(input())
ans=''
for moji in S:
    if moji!=S[K-1]:
        ans+='*'
    else:
        ans+=moji
print(ans)