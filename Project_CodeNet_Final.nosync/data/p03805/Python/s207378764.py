graph=[[False for _ in range(8)] for _ in range(8)]
visited=[False for _ in range(8)]

def dfs(v,N,visited):
    all_visited=True
    for i in range(N):
        if(visited[i]==False):
            all_visited=False

    if(all_visited):
        return 1

    ret=0

    for i in range(N):
        if(graph[v][i] == False):
            continue
        if(visited[i]):
            continue
        visited[i]=True
        ret = ret + dfs(i,N,visited)
        visited[i]=False
    return ret


def main():
    N,M=map(int,input().split())

    for _ in range(M):
        A,B=map(int,input().split())
        graph[A-1][B-1]=True
        graph[B -1][A-1]=True

    
    visited[0]= True
    print(dfs(0,N,visited))

if __name__ == "__main__":
    main()

