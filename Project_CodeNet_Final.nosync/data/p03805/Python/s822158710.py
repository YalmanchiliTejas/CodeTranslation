import itertools

N, M = map(int, input().split())
ab=[]
for _ in range(M):
    ab.append(tuple(map(int, input().split())))

lst=[[] for _ in range(N+1)]
for el in ab:
    lst[el[0]].append(el[1])
    lst[el[1]].append(el[0])
#print(lst)

count=0
for permu in itertools.permutations(range(1,N+1)):
    if permu[0] == 1:
        for i in range(0,N-1):
            if permu[i+1] in lst[permu[i]]:
                pass
            else:
                break
        else:
            count+=1
            #print(permu)
print(count)

