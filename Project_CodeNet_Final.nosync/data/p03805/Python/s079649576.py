import copy

N,M = map(int,input().split())
t_dict = dict()
for _ in range(M):
    a,b = map(int,input().split())
    try:
        t_dict[a] += [b]
    except KeyError:
        t_dict[a] = [b]
        
    try:
        t_dict[b] += [a]
    except KeyError:
        t_dict[b] = [a]
        

origin = [1]
new_origin = []
for one in t_dict[1]:
    new_origin.append(origin+[one])

for _ in range(N-2):
    origin = copy.deepcopy(new_origin)
    new_origin = []
    for one in origin:
        for two in t_dict[one[-1]]:
            if two  in one :
                pass
            else:
                new_origin.append(one+[two])
                
print(len(new_origin))