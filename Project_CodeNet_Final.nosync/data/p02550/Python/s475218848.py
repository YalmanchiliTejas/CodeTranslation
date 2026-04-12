n,x,m = map(int,input().split())

place = [0] * m
place[x] = 1
cur = [x]
ends = 0

for i in range(m):
    x = (x**2) % m
    if place[x] == 0:
        place[x] = i+2
        cur.append(x)
    else:
        ends = i+2
        break
        
roopsum = sum(cur[place[x]-1:ends-1])
rooplen = ends - place[x]
curlen = cur[place[x]-1:]

mm = min(n,ends-1)
ans = 0

for i in range(mm):
    ans += cur[i]
    
if n-mm == 0:
    print(ans)
else:
    roopamo = (n-mm) // rooplen
    roopama = (n-mm) % rooplen
    
    ans += roopamo * roopsum
    for i in range(roopama):
        ans += curlen[i]
        
    print(ans)