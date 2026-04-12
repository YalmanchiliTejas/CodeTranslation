
import heapq

def prime_method():
    not_went = [True] * n  # n個の点に行ったかという話
    edges = []
    start = graph[0]
    for e in start:
        heapq.heappush(edges,e)
    not_went[0] = False
    cost = 0
    while len(edges) != 0:
        minedge = heapq.heappop(edges)
        if not not_went[minedge[1]]:
            continue
        v = minedge[1]
        gv = graph[v]
        not_went[v] = False
        for temp in gv:
            if not_went[temp[1]]:  # その頂点に行ってなければ
                heapq.heappush(edges, temp)
        cost += minedge[0]
    return cost
    # a[1] = [[2,3],[5,11]] → 点1からコスト2で頂点3に行ける辺、点1からコスト5で頂点11に行ける辺がある


n = int(input())
graph = [[] for i in  range(n)]
cities = []
for i in range(n):
    cities.append(tuple(map(int,input().split()))+tuple([i]))


citiesX=sorted(cities,key=lambda x:x[0])
citiesY=sorted(cities,key=lambda x:x[1])

for i in range(n-1):
    graph[citiesX[i][2]].append(((citiesX[i+1][0] - citiesX[i][0]),citiesX[i+1][2]))
    graph[citiesX[i+1][2]].append(((citiesX[i+1][0] - citiesX[i][0]),citiesX[i][2]))
    graph[citiesY[i][2]].append(((citiesY[i+1][1] - citiesY[i][1]),citiesY[i+1][2]))
    graph[citiesY[i+1][2]].append(((citiesY[i+1][1] - citiesY[i][1]),citiesY[i][2]))
print(prime_method())