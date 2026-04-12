n=int(input())
s=[]
for i in range(n):
 s.append(input())
 t=sorted(list(set(s[0])))
 ans=""
for l in t: 
 cnt = min([s[i].count(l) for i in range(n)])
 ans += l*cnt
print(ans)
