from itertools import permutations

n,m=map(int,input().split())
path=set()
for _ in range(m):
    u,v=map(int,input().split())
    path|={(u-1,v-1),(v-1,u-1)}
s = 0
for i in permutations(range(n)):
    if i[0] ==0:

        s+=(all((h,j) in path for h,j in zip(i[1:],i)))


print(s)