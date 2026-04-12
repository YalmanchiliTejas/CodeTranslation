import itertools

N,M=map(int,input().split())
ab=[]
for i in range(M):
    a,b=map(int,input().split())
    ab.append([a,b])

per=[i for i in range(2,N+1)]
permu=[]
for i in itertools.permutations(per):
    lst=[1]
    lst.extend(i)
    permu.append(lst)
num=0
for lst in permu:
    can=True
    for i in range(N-1):
        if not([lst[i],lst[i+1]] in ab) and not([lst[i+1],lst[i]] in ab):
            can=False
            break
    if can:
        num+=1
print(num)
