n=int(input())
s=list(str(input()))
k=int(input())

for i in range(n):
    if s[i]!=s[k-1]:
        s[i]="*"
ans=""
for x in s:
    ans+=x
print(ans)
