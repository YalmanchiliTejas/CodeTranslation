from itertools import permutations

N,M = map(int, input().split())
AB = set()
for i in range(M):
    A,B = map(int, input().split())
    AB.add((A-1,B-1))

s = ""
for i in range(1,N):
    s = s + str(i)
    
paths = permutations(s,N-1)
paths = list(paths)

ans = 0
for path in paths:
    path = [0] + [int(i) for i in path]

    for i in range(N-1):
        if (not (path[i],path[i+1]) in AB) and (not (path[i+1], path[i]) in AB):
            break
        
        if i == N-2:
            ans += 1
    
print(ans)