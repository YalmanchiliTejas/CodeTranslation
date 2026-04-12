from itertools import*
n,*t=map(int,open(0).read().split())
e={0}
for a in zip(t[1::2],t[2::2]):e|={a,a[::-1]}
print(sum(all(u in e for u in zip(t,t[1:]))for t in permutations(range(1,n+1))if t[0]<2))