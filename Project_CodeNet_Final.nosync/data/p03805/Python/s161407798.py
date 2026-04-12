N, M = map(int, input().split())

AB = []
for i in range(M):
    ab = list(map(int, input().split()))
    AB.append(ab)
    
import itertools

per = list(itertools.permutations(list(range(2, N+1))))

count = 0
for i in range(len(per)):
    #print(per[i])
    path = [1] + list(per[i])
    #print(path)
    
    for j in range(len(path)-1):
        p1 = [path[j], path[j+1]]
        p2 = [path[j+1], path[j]]
        if (p1 not in AB) and (p2 not in AB):
            break
    else:
        count += 1
        
print(count)