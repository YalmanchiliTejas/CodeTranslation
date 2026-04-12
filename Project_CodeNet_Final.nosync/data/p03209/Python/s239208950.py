N, X = map(int, input().split())

# メモ化するための初期化
a, p = [1], [1]
for i in range(N):
    a.append(a[i] * 2 + 3)
    p.append(p[i] * 2 + 1)

def f(N, X):
    # レベル0
    if N == 0:
        # 0層以下
        if X <= 0: # X <= 0 や X > a_N を許容し解説本文から簡略化
            return 0
        # 1層以上 (レベル0から実質1層のみ)
        else:
            return 1
    # レベル1以上
    # B ~ 以下
    elif X <= 1 + a[N - 1]:
        return f(N - 1, X - 1)
    # B ~ P ~ B 以下
    else:
        return p[N - 1] + 1 + f(N - 1, X - 2 - a[N - 1])

print(f(N, X))
