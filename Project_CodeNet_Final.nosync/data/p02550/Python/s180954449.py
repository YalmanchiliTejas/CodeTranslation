n, x, m = map(int, input().split())

loop = [0]*m

a = x
is_loop = False
for i in range(n):
        if loop[a] == 1:
            # あまりがループしている
            loop[a] += 1
            is_loop = True
            break
        else:
            # ループしていない
            loop[a] = 1
            a = (a**2)%m

if not is_loop:
    # ループしなかった
    ans = 0
    for i in range(m):
        ans += i*loop[i]
    print(ans)
else:
    # ループした
    # 1. ループ長を求める
    def get_loop_length(b):
        c = 1
        s = b
        b_tmp = b
        while True:
            b_tmp = (b_tmp**2)%m
            if b == b_tmp:
                return c, s
            else:
                c += 1
                s += b_tmp
    loop_length, loop_sum = get_loop_length(a)
    # 2. ループに入るまでをシミュレーション、計算、シミュレーション
    ans = 0
    b = x
    # ループまで
    while b != a:
        ans += b
        b = (b**2)%m
        n -= 1
    # ループ中
    ans += loop_sum*(n//loop_length)
    n = n % loop_length
    b = a
    for i in range(n):
        ans += b
        b = (b**2)%m
    print(ans)
