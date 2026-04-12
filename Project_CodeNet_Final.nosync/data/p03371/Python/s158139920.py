l = list(input().split())
c = 0
for i in l:
 l[c] = int(i)
 c+=1

k = min(l[3],l[4])
money = min((l[0]+l[1])*k, l[2]*2*k)

if l[3]>l[4]:
 m = l[3]-l[4]
 money += min(l[0], l[2]*2)*m
else:
 m = l[4]-l[3]
 money += min(l[1], l[2]*2)*m

print(money)