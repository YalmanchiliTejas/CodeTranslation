N, X = map(int, input().split())

a = [1]
p = [1]
for i in range(1, N+2):
    a.append(2 * a[i-1] + 3)
    p.append(2 * p[i-1] + 1)

def calc(N, X): #レベルNバーガーの下からX層に含まれるパティの枚数
    if N == 0: #全てパティ
        if X == 0:
            return 0
        else:
            return 1
    if X == 1:
        return 0
    # print (N - 1)
    if 1 < X <= 1 + a[N - 1]:
        # print ('A')
        return calc(N - 1, X - 1)
    if X == 2 + a[N - 1]:
        # print ('B')
        return p[N - 1] + 1
    if 2 + a[N - 1] < X <= 2 + 2 * a[N - 1]:
        # print ('C')
        return p[N - 1] + 1 + calc(N - 1, max(X - 2 - a[N - 1], 0))
    if X == 3 + 2 * a[N - 1]:
        # print ('D')
        return p[N]

print (calc(N, X))