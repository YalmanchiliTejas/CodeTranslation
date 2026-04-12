N,M = (int(i) for i in input().split()) 
edge = []
for _ in range(N):
    edge.append([False] * N) 
for _ in range(M):
    a,b =  (int(i) - 1 for i in input().split())  
    edge[a][b] =True
    edge[b][a] = True


COUNT = 0
def func(choose,choosen,count):
    new_count = count
    if len(choose) == 0:
        can_move =True
        for i in range(len(choosen) - 1):
            can_move = can_move and edge[choosen[i]][choosen[i+1]]
        if can_move:
            #print('sex')
            return count + 1
        return count
    for i in range(len(choose)):
        new_choosen = choosen + [choose[i]]
        new_count = func(choose[:i] + choose[i + 1:],new_choosen,new_count)
    return new_count

a = func([i for i in range(1,N)],[0],0)
print(a)
