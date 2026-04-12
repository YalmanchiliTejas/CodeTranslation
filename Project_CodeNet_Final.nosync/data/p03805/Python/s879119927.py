n,m = map(int,input().split())

import numpy as np
graph = np.zeros((n,n))
for i in range(m):
    a,b = map(int,input().split())
    graph[a-1][b-1] = graph[b-1][a-1] = 1

from itertools import permutations
nv = [i for i in range(1,n)]
def main():
    def checkroot(root,graph):
        if graph[0][root[0]] == 0:
            return 0
        for i in range(1,len(root)):
            if graph[root[i]][root[i-1]]==0:
                return 0
        return 1

    ans = 0
    for root in permutations(nv):
        if checkroot(root,graph)==1:
            ans += 1
    print(ans)

if __name__ == "__main__":
    main()