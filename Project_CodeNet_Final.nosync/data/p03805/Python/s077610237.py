import itertools
N,M=map(int,input().split())
path=[tuple(map(int,input().split())) for _ in range(M)]
cnt=0
for li in itertools.permutations([k for k in range(2,N+1)],N-1):
    flag=True
    li=list(li)
    li.insert(0,1)
    for i in range(N-1):
        if (li[i],li[i+1]) not in path and (li[i+1],li[i]) not in path:
            flag=False
    if flag:
        cnt+=1
print(cnt)