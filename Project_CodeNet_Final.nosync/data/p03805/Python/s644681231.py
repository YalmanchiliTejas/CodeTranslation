import itertools

def main():
    N, M = map(int, input().split())
    VE = tuple(tuple(map(lambda x: int(x)-1, input().split())) for _ in range(M))
    # print(VE)

    adj_mat = [[0 for _ in range(N)] for _ in range(N)]
    for ve in VE:
        adj_mat[ve[0]][ve[1]] = 1
        adj_mat[ve[1]][ve[0]] = 1
    # for row in adj_mat:
    #     print(row)

    ans = 0
    for perm in itertools.permutations([i for i in range(1, N)]):
        # print(perm)
        flag = True
        now_V = 0
        for next_V in perm:
            # print('{} to {}'.format(now_V, next_V))
            # print('{}'.format(adj_mat[now_V][next_V]))
            if not adj_mat[now_V][next_V]:
                flag = False
                break
            now_V = next_V
        if flag:
            ans += 1

    print(ans)

if __name__ == '__main__':
    main()
