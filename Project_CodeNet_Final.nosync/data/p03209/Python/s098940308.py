N, X = map(int, input().split())


def saiki(n, x):
    #print(n, x)
    if n == 5:
        if x == 1:
            return 0
        elif x <= 4:
            return x-1
        else:
            return 3

    if x <= 1:
        return 0
    elif x <= 1 + (n-3)//2:
        return saiki((n-3)//2, x-1)
    elif x == 1 + (n-3)//2 + 1:
        return saiki(x - 2, x - 2) + 1
    elif x <= 1 + (n-3)//2 + 1 + (n-3)//2:
        return saiki((n - 3) // 2, (n - 3) // 2) + 1 + saiki((n - 3) // 2, x - ((n-3)//2+2))
    else:
        return 2 * saiki((n - 3) // 2, (n - 3) // 2) + 1


maisu = 1
for i in range(N):
    maisu = 2 * maisu + 3

ans = saiki(maisu, X)

print(ans)
