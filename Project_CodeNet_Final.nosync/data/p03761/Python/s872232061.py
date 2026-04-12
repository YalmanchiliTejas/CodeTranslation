n=int(input())
abc=list("abcdefghijklmnopqrstuvwxyz")

D={}
for a in abc:
    D[a]=0

for i in range(n):
    s=input()
    for a in abc:
        now=D[a]
        num=s.count(a)
        if i==0:
            D[a]=num
        else:
            D[a]=min(now,num)
ans=""

for s,v in D.items():
    ans+=s*v
ans="".join(sorted(ans))
print(ans)

        
