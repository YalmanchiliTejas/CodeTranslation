import sys
import itertools
sys.setrecursionlimit(10**9)
INF=10**18
def input():
    return sys.stdin.readline().rstrip()

def main():
    N,M=map(int,input().split())
    edge=[[] for _ in range(N)]
    for i in range(M):
        a,b=map(lambda x:int(x)-1,input().split())
        edge[a].append(b)
        edge[b].append(a)
    l=list(range(1,N))
    ps=itertools.permutations(l)
    ans=0
    for p in ps:
        node=0
        for nextnode in p:
            if nextnode in edge[node]:
                node=nextnode
            else:
                break
        else:
            ans+=1
    print(ans)

if __name__ == '__main__':
    main()
