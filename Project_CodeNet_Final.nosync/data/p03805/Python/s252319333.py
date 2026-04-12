#54c
import itertools
N,M = map(int, input().split())

from_to_dict = dict()

for i in range(M):
    a,b = map(int, input().split())
    
    if a in from_to_dict:
        from_to_dict[a].add(b)
    else:
        from_to_dict[a] = set([b])
        
    if b in from_to_dict:
        from_to_dict[b].add(a)
    else:
        from_to_dict[b] = set([a])
        
#候補は全部で8! = 40320通り。総当たりでOK
candidate_list = [i+1 for i in range(N)]
ans = 0

for candidate in list(itertools.permutations(candidate_list)):
    if candidate[0] == 1:
        for i in range(len(candidate)-1):
            from_node = candidate[i]
            to_node = candidate[i+1]

            if to_node not in from_to_dict[from_node]:
                break
        else:
            ans += 1
                          
print(ans)