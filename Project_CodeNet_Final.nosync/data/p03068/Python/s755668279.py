import copy
n=int(input())
s=input()
k=int(input())

lsts=list(s)
a=k-1
chara=lsts[a]

ss=copy.copy(s)
lstss=list(ss)

for i in range(n):
    if lstss[i]!=chara:
        lsts[i]="*"

ans=""
for i in range(n):
    ans+=lsts[i]

print(ans)