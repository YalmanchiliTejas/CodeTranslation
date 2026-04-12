n=int(input())
s=input()
k=int(input())
ans=s[k-1]
#print(ans)
if s[0]==ans:
    atai=s[0]
else:
    atai='*'
for i in range(1,n):
    if s[i]==ans:
        atai=atai+s[i]
    else:
        atai=atai+'*'

print(atai)
