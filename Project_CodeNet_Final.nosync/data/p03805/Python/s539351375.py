from itertools import permutations

n,m = map(int,input().split(' '))
choices = permutations(range(1,n))
nords = [[]for _ in range(n)]
for i in range(m):
    a, b = map(lambda x : int(x)-1,input().split(" "))
    nords[a].append(b)
    nords[b].append(a)


ans = 0
for choice in choices:
    row = list(choice)
    row.insert(0,0)
    for i,nownord in enumerate(row):
        if i== n - 1 :
            ans += 1
            break
        nextnord = row[i+1]
        if not nextnord in nords[nownord]:
            break
            
            
print(ans)



