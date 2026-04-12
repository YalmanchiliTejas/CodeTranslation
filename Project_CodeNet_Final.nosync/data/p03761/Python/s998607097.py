ans=''
n=int(input())
s=[]
for i in range(n):
    s.append(input())
ss=sorted(list(set(s[0])))
for l in ss:
    c=min([s[j].count(l) for j in range(n)])
    ans=ans+l*c
print(ans)