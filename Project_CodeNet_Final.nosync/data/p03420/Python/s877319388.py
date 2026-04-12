
def solve1():
    n, k = map(int, input().split())

    ans = 0
    for i in range(1, n+1):
        for j in range(1, n+1):
            if i % j >= k:
                ans += 1
    print(ans)


def solve():
    n, k = map(int, input().split())

    # k0は例外処理
    if k == 0:
        print(n**2)
        return

    # 割る数Bを増やしながら考える
    # b<=kまでは、割る数がk以下なのであまりは絶対kを超えない
    # K<b以降（b=k+1～n）
    ans = 0
    for b in range(k+1, n+1):
        n_iter = (n+1)//b
        amari = (n+1) % b

        #print(n_iter, b, k, n_iter*(b-k), amari, max(0, amari-k))
        ans += n_iter * (b-k)
        ans += max(0, amari-k)

    # B>=Kのところ
    # どうやってもあまりはK以上にならないので数えない

    print(ans)

solve()