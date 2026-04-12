n=int(input())
d={chr(i):51 for i in range(97,97+26)}

for i in range(n):
    s=input()
    for key in d:
        d[key]=min(d[key],s.count(key))
ans=''
for key in d:
    ans+=key*d[key]
print(ans)
