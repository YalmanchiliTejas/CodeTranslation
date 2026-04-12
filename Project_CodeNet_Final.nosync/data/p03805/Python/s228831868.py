import itertools
N,M=map(int,input().split())
l=list(itertools.permutations(range(N-1)))
h=[set(map(int, input().split())) for i in range(M)]
a=0
for i in range(len(l)):
    for k in range(M):
        if {1,l[i][0]+2}==h[k]:
            break
    else:
        continue
    for j in range(1,N-1):
        for k in range(M):
            if {l[i][j-1]+2,l[i][j]+2}==h[k]:
                break
        else:
            break
    else:
        a+=1
print(a)