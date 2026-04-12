import copy
n,m = map(int,input().split(' '))
route = [[]for i in range(n+1)]
already = [0 for i in range(n+1)]
already[0:2]=[1,1]
cnt=0

for i in range(m):
    a,b = map(int,input().split(' '))
    route[a].append(b)
    route[b].append(a)

def trace(index,already):
    global cnt
    # print(index,already)
    if not(0 in already):
        cnt += 1
    else:
        for new_point in route[index]:
            if already[new_point]!=1:
                new_already = copy.copy(already)
                new_already[new_point] = 1
                trace(new_point,new_already)

trace(1,already)

print(cnt)