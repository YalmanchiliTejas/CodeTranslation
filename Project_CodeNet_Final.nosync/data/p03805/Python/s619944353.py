from itertools import permutations
def main():
    N,M = map(int, input().split())
    edge = [[False]*N for _ in range(N)]
    for i in range(M):
        a,b = map(lambda x:x-1, map(int, input().split()))
        edge[a][b] = True
        edge[b][a] = True
    ans = 0
    for perm in permutations([i for i in range(1,N)]):
        arrived = [False]*N
        flag = False
        prev = 0
        for p in perm:
            # edgeが存在しない
            if not edge[prev][p]:
                flag = True
                break
            # edgeが存在
            else:
                # 過去に訪れた
                if arrived[p]:
                    flag = True
                    break
                else:
                    arrived[p] = True
            prev = p
        if not flag:
            ans += 1
    print(ans)
main()
