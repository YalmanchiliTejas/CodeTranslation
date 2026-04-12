def resolve():
    H, W = map(int, input().split())
    A = []
    count = 0
    ans = []
    for _ in range(H):
        a = input()
        flag = 0
        for __ in range(W):
            if a[__] == "#":
                flag = 1
        if flag == 1:
            A.append(a)
            count += 1
    for i in range(W):
        flag = 0
        for j in range(count):
            if A[j][i] == "#":
                flag = 1
        if flag == 0:
            ans.append(i)
    for p in range(count):
        anan = ""
        for q in range(W):
            if q not in ans:
                anan += A[p][q]
        print(anan)
resolve()