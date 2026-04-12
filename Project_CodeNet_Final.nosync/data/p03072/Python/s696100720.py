n=int(input())
h=[int(i) for i in input().split()]
ans=0
chk=h[0]
for i in h:
    if i>=chk:
         ans+=1
         chk=i
print(ans)
