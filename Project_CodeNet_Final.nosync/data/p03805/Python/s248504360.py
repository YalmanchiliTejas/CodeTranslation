import itertools
from pprint import pprint

n,m = map(int,input().split())

sides = [list(map(int,input().split())) for _ in range(m)]

#頂点を並び変える順列の総パターンを考える（ただし最初は「1」で固定）。
#総数は(N-1)! -> 7! -> 5040
#よって全探索は余裕そう。

vertexes = list(itertools.permutations(range(2,n+1)))

#pprint(vertexes)

counter = 0


for v in vertexes:
    #最初は1が始点
    for s in sides:
        if s[0] == 1 and s[1] == v[0]:
            break
        elif s[1] == 1 and s[0] == v[0]:
            break
    else:
        #この数列vはダメなので次のループへ
        continue

    for j in range(n-2):
        for s in sides:
            if v[j] == s[0] and v[j+1] == s[1]:
                break
            elif v[j] == s[1] and v[j+1] == s[0]:
                break
        else:
            break
    else:
        counter += 1



print(counter)
    

        

