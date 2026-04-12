n,m = map(int,input().split())
path = [input().split() for x in range(m)]

table = [[] for x in range(n)]
for x in path:
    table[int(x[0])-1].append(int(x[1])-1)
    table[int(x[1])-1].append(int(x[0])-1)
    
import itertools
count = 0
for z in itertools.permutations(range(0,n)):
    if z[0] == 0:
        for y in range(len(z)-1):
            if z[y+1] in table[z[y]]:
                continue
            else:
                count -= 1
                break
        count += 1
print(count)