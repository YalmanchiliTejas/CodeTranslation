n = int(input())

l = []
for i in range(n):
    l.append(input())
    
l_sorted  = sorted(set(l[0]))
ans=""

for k in l_sorted:
    cnt = min(l[i].count(k) for i in range(n))
    ans += k*cnt
print(ans)