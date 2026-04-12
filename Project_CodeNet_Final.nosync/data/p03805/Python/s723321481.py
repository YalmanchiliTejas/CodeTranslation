from collections import defaultdict
import queue

def dfs(P,V,s,cnt):
    V[s] = 1
    # print(V)
    # 全部辿ったらインクリメント
    if len(V) == sum(V):
        cnt += 1
        # print('count',str(cnt))

    for t in P[s]:
        if V[t] > 0:
            continue
        # print(s,t)
        V,cnt = dfs(P,V,t,cnt)
    V[s] = 0
    return V,cnt

def main():
    N,M = [int(x) for x in input().split()]
    paths = []
    for _ in range(M):
        a,b = [int(x) for x in input().split()]
        paths.append((a,b))

    # 隣接リスト
    P = defaultdict(list)
    for a,b in paths:
        P[a-1].append(b-1)
        P[b-1].append(a-1)

    V = [0]*N
    s = 0
    cnt = 0
    # print(P)
    V,cnt = dfs(P,V,s,cnt)
    print(cnt)


if __name__ == '__main__':
    main()
