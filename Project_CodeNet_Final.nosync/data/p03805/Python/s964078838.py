import sys


def resolve():
    import itertools
    readline = sys.stdin.readline    # 1行だけ文字列にする

    N, M = map(int, readline().split())
    lst = [set(map(int, readline().split())) for _ in [0] * M]
    d = []
    ans = 0
    # for i in range(2, N + 1):
    #     d.append(i)
    for i in itertools.permutations(range(2, N + 1), N - 1):
        cnt = 0
        if {1, i[0]} in lst:
            cnt += 1
            for j in range(N - 2):
                if {i[j], i[j + 1]} in lst:
                    cnt += 1
                    pass
                else:
                    break
        if cnt == N - 1:
            ans += 1
    print(ans)
    

if __name__ == "__main__":
    resolve()