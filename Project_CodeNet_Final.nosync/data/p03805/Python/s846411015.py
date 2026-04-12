## coding: UTF-8
from itertools import permutations

N,M = map(int,input().split())

graph = []
for i in range(M):
    graph.append(list(map(int, input().split())))
#print(graph)

point = [i+1 for i in range(1,N)]
root = list(permutations(point, N-1))
#print(root)

counter = 0
for i in range(len(root)):
    pairs = []
    pairs.append([1, root[i][0]])
    #print(root[i])
    for j in range(N-2):
        pairs.append([root[i][j], root[i][j+1]])
    #print('i:{},root[i]:{},pairs:{}'.format(i, root[i], pairs))
    status = True
    for k in range(len(pairs)):
        tester = sorted(pairs[k])
        #print('pairs[k]:{}, tester:{}, in graph?:{}'.format(pairs[k], tester, (tester in graph)))
        if(not(tester in graph)):
            status = False
    #print('status:{}'.format(status))
    if(status):
        counter += 1
print(counter)

'''
counter = 0
for i in range(len(root)):
    print('i:{},root[i]:{}'.format(i, root[i]))
    spot = 1
    for j in range(N-1):
        #勧めるなら進む
        n = root[i][j]
        print('spot:{}, n:{}'.format(spot, n))
        if(spot < n):
            if([spot, n] in graph):
                spot = n
            else:
                continue
        elif(spot > n):
            if([n, spot] in graph):
                spot = n
            else:
                continue
        else:
            continue
'''        



