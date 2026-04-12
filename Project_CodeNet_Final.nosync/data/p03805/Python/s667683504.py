import itertools
N,M=map(int,input().split())
edges={tuple(sorted(map(int,input().split()))) for i in range(M)}
ans=0
for i in itertools.permutations(range(2,N+1),N-1):
    l=[1]+list(i)
    #ans+=sum(1 for edge in zip(l,l[1:]) if tuple(sorted(edge)) in edges)==N-1 以下はこの式を展開して書き直したもの
    sum=0
    for edge in zip(l,l[1:]): #これでlの1個目と2個目をとりだしたもの→2個目と3個目をとりだしたものみたいな感じになる
        if tuple(sorted(edge)) in edges:
            sum+=1
    if sum==N-1:
        ans+=1
print(ans)