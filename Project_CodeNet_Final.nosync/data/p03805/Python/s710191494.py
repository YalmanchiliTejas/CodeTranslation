from itertools import permutations

N, M = map(int, input().split())

abs = [list(map(int,input().split())) for _ in range(1, M+1)]
          
p_paths = list(permutations(list(range(2,N+1)), N-1))


cnt=0

for p_path in p_paths:
    p_path = list(p_path)
    p_path.insert(0, 1)
    c=0
    for i in range(len(p_path)-1):
        for ab in abs:

            if ab == list([p_path[i], p_path[i+1]]) or ab == list([p_path[i+1], p_path[i]]):
                c+=1
                break
        if c==len(p_path)-1:
            cnt=cnt+1
print(cnt)
                   
