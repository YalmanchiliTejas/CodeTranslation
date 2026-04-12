from itertools import permutations
def main():
    n, m = map(int, input().split())

    edge = set()
    for _ in range(m):
        a, b = map(lambda x: int(x)-1, input().split())
        edge.add((a, b))  
        edge.add((b, a))

    #全ノード間に辺が張っていると仮定する
    #このとき全てのノードを廻る順番は順列の数だけある
    #ここから条件を絞って数えるべきものを数えていく 

    #ノードを廻る順を構成する 
    node_num = []
    for i in range(n):
        node_num.append(i)
    
    cnt = 0
    for p in permutations(node_num):
        #数える経路は始点が0である
        if p[0] == 0:
            #この順列pの通りに辿れるように辺が張っているならこの経路は数えるべき経路である
            flag = True
            for i in range(n-1):
                #この順列のあるノード間に辺が存在しないならこの経路は不可能
                if (p[i], p[i+1]) not in edge:
                    flag = False
            if flag:
                cnt += 1 
    print(cnt) 
main()