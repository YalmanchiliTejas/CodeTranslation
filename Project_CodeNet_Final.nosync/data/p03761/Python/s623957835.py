n=int(input())
l=[list(input()) for i in range(n)]
s=set()
for i in l:
    for j in i:
        s.add(j)
s=sorted(s)
x=[[] for i in range(len(s))]

for i in range(len(s)):
    for j in range(n):
        x[i].append(l[j].count(s[i]))

ans=[]
for i in range(len(s)):
    ans.append(s[i]*min(x[i]))
print("".join(ans))
