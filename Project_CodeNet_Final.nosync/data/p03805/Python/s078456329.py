from itertools import permutations 

N, M = map(int, input().split())
a = [list(map(int, input().split())) for _ in range(M)]

answer = 0 
for path in permutations(range(2, N+1)):
    path = [1] + list(path)
    found = True 
    for i in range(1, len(path)):
        if not [path[i], path[i-1]] in a and not [path[i-1], path[i]] in a:
            found = False
            break
    if found:
        answer += 1
print(answer)