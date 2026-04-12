import itertools

n,m= map(int, input().split())
a= [list(map(int, input().split())) for i in range(m)]
# 経路全探索
ans=0
for v in itertools.combinations(a, n-1):
    b=[[] for i in range(n)]
    for x,y in v:
        b[x - 1].append(y - 1)
        b[y - 1].append(x - 1)

    import collections
    from collections import deque


    def tree(s):

        INF = -10 ** 9
        dis = [INF for i in range(n)]
        dis[s] = 0

        def bfs():
            d = deque()
            d.append(s)

            while len(d):
                x = d.popleft()

                for i in range(len(b[x])):
                    y = b[x][i]
                    if dis[y] == INF:
                        d.append(y)
                        dis[y] = dis[x] + 1

            return max(dis)

        return bfs()
    if tree(0)==n-1:
        ans+=1

print(ans)