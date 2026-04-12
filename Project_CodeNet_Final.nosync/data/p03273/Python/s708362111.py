import numpy as np
h,w = map(int,input().split())
graph = [['.' for j in range(w)]for i in range(h)]


for i in range(h):
    tmp = input()
    for j in range(len(tmp)):
        graph[i][j] = tmp[j]
graph = np.array(graph)

flag = True
while flag:
    flag = False
    for i in range(graph.shape[1]):
        if( graph[:,i] == ['.']*graph.shape[0]).all():
            flag = True
            if i == 0:
                graph = graph[: , 1:]
                break
                
            if i == graph.shape[1] -1:
                graph = graph[:,:i]
                break
                
            else:
                graph = np.concatenate([graph[:,:i],graph[:,i+1:] ], 1)
                break
                
    for i in range(graph.shape[0]):
        if (graph[i,:] == ['.']*graph.shape[1]).all():
            flag = True
            if i == 0:
                graph = graph[1: , :]
                break
                
            if i == graph.shape[0] -1:
                graph = graph[:i,:]
                break
                
            else:
                graph = np.concatenate([graph[:i , :],graph[i+1: , :] ], 0)
                break
                
for i in graph:
    print(*i, sep="")