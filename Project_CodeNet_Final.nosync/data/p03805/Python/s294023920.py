import itertools

n,m = [int(x) for x in input().split()]
li = []
for _ in range(m):
    li.append({int(x) for x in input().split()})

a = itertools.permutations(range(2,n+1))
count = 0
for i in a:
    x = [1] + list(i)
    for i in range(n-1):
        if not {x[i],x[i+1]} in li:
            break
    else:
        count += 1
print(count)
