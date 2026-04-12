import copy

N,M = map(int,input().split(' '))
graph_releation = [[] for _ in range(N)]
for _ in range(M):
    a,b = map(int,input().split(' '))
    graph_releation[a-1].append(b-1)
    graph_releation[b-1].append(a-1)
#print(graph_releation)

result_list = []

def search_graph(graph_releation,result_list,current_idx=0,path=[0]):
    for i in range(len(graph_releation[current_idx])):
        next_idx = graph_releation[current_idx][i]
        tmp_path = copy.deepcopy(path)
        if next_idx in tmp_path:
            continue
        tmp_path.append(next_idx)
        if len(tmp_path) == len(graph_releation):
            result_list.append(tmp_path) #確定
            continue
        else:
            search_graph(graph_releation,result_list,next_idx,tmp_path)

search_graph(graph_releation,result_list)
print(len(result_list))