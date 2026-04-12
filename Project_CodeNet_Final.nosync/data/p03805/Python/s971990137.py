N,M=map(int,input().split())
hen=[[] for i in range(0,N)]
for i in range(0,M):
    a,b=map(int,input().split())
    hen[a-1].append(b-1)
    hen[b-1].append(a-1)

def onestrokepath(start,visited=[]):
    flag=0
    count=0
    for next in hen[start]:
        if not next in visited:
            flag=1
            count+=onestrokepath(next,visited+[next])
    if flag==0:
        check=[i for i in range(0,N)]
        visited.sort()
        if check==visited:
            return 1
        else:
            return 0
    return count

print(onestrokepath(0,[0]))
