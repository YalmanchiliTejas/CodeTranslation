import itertools

n,m = map(int,input().split())
path_list = [list(map(int,input().split())) for _ in range(m)]

path_dict = {}
count = 0

for path in path_list:
    if path[0] in path_dict:
        path_dict[path[0]].append(path[1])
    else:
        path_dict[path[0]] = [path[1]]
    if path[1] in path_dict:
        path_dict[path[1]].append(path[0])
    else:
        path_dict[path[1]] = [path[0]]

order_list = list(range(2,n+1))
order_list = list(itertools.permutations(order_list))
# print(list(itertools.permutations(order_list)))
for order in order_list:
    order = list(order)
    order.insert(0,1)
    for i,num in enumerate(order):
        if i >= 1:
            if num not in target_list:
                break
        if i == len(order)-1:
            count += 1
        target_list = path_dict[num]

print(count)