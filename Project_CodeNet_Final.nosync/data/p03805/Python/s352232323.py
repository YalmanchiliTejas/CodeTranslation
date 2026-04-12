import itertools
(n,_),*a= [[*map(int,i.split())] for i in open(0)]
p=[[1] + list(i) for i in itertools.permutations(range(2,n+1),n-1)]
c = 0
for i in p:
    for j in range(n-1):
        if sorted([i[j],i[j+1]]) not in a:
            break
    else:
        c+=1
print(c)