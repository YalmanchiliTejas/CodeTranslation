
def search(N,adj):
    visited={1:[1]}
    S=[[1]]
    paths=[]
    while len(S)!=0:
        p=S.pop()
        if len(p)==N:
            paths.append(p)
        else:
            for w in adj[p[-1]]:
                if w not in p:
                    S.append(p+[w])
    return paths


if __name__ == '__main__':
    N,M=list(map(int,input().split()))
    ad={x:[] for x in range(1,N+1)}
    for i in range(M):
        a,b=list(map(int,input().split()))
        ad[a].append(b)
        ad[b].append(a)
    print(len(search(N,ad)))










