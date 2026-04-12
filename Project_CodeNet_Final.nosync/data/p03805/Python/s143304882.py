from itertools import *
f=lambda:map(int,input().split())
N,M=f()
a=[[*f()] for i in range(M)]
a=[*a,*[[y,x] for x,y in a]]
p=[(1,*i)for i in [*permutations(range(2,N+1))]]
print([sum(1 for y in range(N-1)if [x[y],x[y+1]] in a)for x in p].count(N-1))