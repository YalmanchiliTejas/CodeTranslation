alpha=list('abcdefghijklmnopqrstuvwxyz')
a=[]
ans=''
n=int(input())
for i in range(n):
    a.append(str(input()))

for s in alpha:
    count=50
    for i in a:
        if i.count(s)<count:
            count=i.count(s)
    ans += s*count

print(ans)