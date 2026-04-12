"一般化うるう年"
while True:
    n, l, r = map(int, input().split())  # 数列の要素の個数はn個, lからrまでのxを試す
    if n == 0:
        break
    A = [int(input()) for _ in range(n)]

    ans = 0
    for x in range(l, r+1):
        flag = True
        for i in range(n):
            if x%A[i] == 0 and (i+1)%2 == 1:
                ans += 1
                flag = False
                break
            elif x%A[i] == 0 and (i+1)%2 == 0:
                flag = False
                break

        if flag:
            if n%2 == 0:
                ans += 1

    print(ans)

