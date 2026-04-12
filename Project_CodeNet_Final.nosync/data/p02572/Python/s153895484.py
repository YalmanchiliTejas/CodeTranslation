if __name__ == '__main__':

    n = int(input())
    A = list(map(int,input().split()))

    #全体
    sm = sum(A) ** 2
    #共通部分
    com = sum([i * i for i in A])

    ans = (sm - com) // 2
    print(ans%(10**9+7))