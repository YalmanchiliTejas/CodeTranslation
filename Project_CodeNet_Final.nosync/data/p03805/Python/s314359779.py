import itertools
N,M=map(int,input().split())
AB=[list(map(int,input().split())) for _ in range(M)] 

t=[i for i in range(N-1)]
premu=list(itertools.permutations(t))

cnt=0
for elem in premu:
    eb=1
    for e in elem:
        ec=e+2
        flag=False
        for ab in AB:
            if (ec in ab) and (eb in ab):
                flag=True    
        if flag:
            eb=ec
        else:
            break
    if flag:
        cnt+=1

print(cnt)
