N, x = map(int, input().split())

n = [1]
p = [1]

for i in range(1, N+1):
    n.append(n[-1] * 2 + 3)
    p.append(p[-1] * 2 + 1)
    
lev = N
n1 = [0, 1, 2, 3, 3]
ans = 0

while lev >= 0:
    if lev ==0:
        ans += 1
        break
    if n[lev]//2 + 2 <= x:
        ans += p[lev-1] + 1
        x -= n[lev-1] + 2
    elif n[lev]//2 + 1 == x:
        ans += p[lev-1] + 1
        break
    elif x==1:break
    else: x -= 1

    lev -= 1
 
print(ans)