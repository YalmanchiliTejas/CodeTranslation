n,m=[int(i) for i in input().split()]
pp=[[0 for i in range(2)] for j in range(m)]
not_bridge=0

#深さ優先探索---------------------------------
#参照元：Python3でグラフの実装＆深さ優先探索・幅優先探索の実装
#http://muromura.hatenablog.com/entry/2017/07/16/025414
def dfs(Graph, Start, Vn, Visited=None):
  
##追加（空から読んでも動くように修正）-----------------------
  if Graph[Start]==[] and Visited==None: 
        Next=Start+1
        dfs(Graph, Next, Vn, Visited)  #再帰
  else:
##--------------------------------------------------------

    if (Visited==None): 
        Visited = [] #開始点のときに探索済みリストをつくる
        Visited.append(Start)  #現在の頂点を探索済みリストに加える

    
    if len(Visited)==Vn: #全点訪問済みの場合、橋ではない
        #print(Visited)
        global not_bridge
        if len(set(Visited)) == n:
            not_bridge=not_bridge+1
#        print(Visited)
        return 0
        
    for Next in Graph[Start]:  #次に探索する頂点の候補
        Visited.append(Next)
        #if ( Next in Visited ):  continue  #訪問済みリストにある頂点は飛ばす
        dfs(Graph, Next, Vn, Visited)  #再帰
        Visited.pop()
    return 0
  
#--------------------------------------------------------        

for i in range(m) :
    pp[i] =[int(i) for i in input().split()]
    
#隣接リスト
l = [[] for i in range(n+1)] #頂点の数+1
for pi in pp:  #0-originedに注意、l[0]は空
    l[pi[0]].append(pi[1])
    l[pi[1]].append(pi[0])

#print(l)
dfs(l, 0, n)
print(not_bridge)