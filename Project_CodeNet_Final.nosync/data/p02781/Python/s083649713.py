N = int(input())
N_digit = len(str(N))
K = int(input())
ans = 0
factorial = [1, 1]
for i in range(2, 101):
    factorial.append(factorial[-1] * i)


def nCr(n, r):
    if n - r < 0:
        return 0
    return factorial[n] // (factorial[r] * factorial[n - r])


if K == 1:
    ans += 9 * (nCr(N_digit - 1, 1))  # 1桁目を0に固定、2桁目以降は自由
    ans += int(str(N)[0])  # 1桁目を考える。2桁目以降は0

elif K == 2:
    ans += (9 ** 2) * (nCr(N_digit - 1, 2))  # 1桁目を0に固定、2桁目以降から自由に2つ
    ans += (int(str(N)[0]) - 1) * 9 * (nCr(N_digit - 1, 1))  # 1桁目を0でなく、かつN以下が確定するように固定
    for d2_position in range(1, N_digit):  # 2つめの0でない数をどこに置くか
        for d2_value in range(1, 10):  # 2つめの0でない数を何にするか
            # 数をつくる
            S = ['0'] * N_digit
            S[0] = str(N)[0]
            S[d2_position] = d2_value
            S = int(''.join(map(str, S)))

            ans += (S <= N)

elif K == 3:
    ans += (9 ** 3) * (nCr(N_digit - 1, 3))  # 1桁目を0に固定、2桁目以降から自由に3つ
    ans += (int(str(N)[0]) - 1) * (9 ** 2) * (nCr(N_digit - 1, 2))  # 1桁目を0でなく、かつN以下が確定するように固定
    for d2_position in range(1, N_digit):  # 2つめの0でない数をどこに置くか
        for d3_position in range(d2_position + 1, N_digit):  # 3つめの0でない数をどこに置くか
            for d2_value in range(1, 10):  # 2つめの0でない数を何にするか
                for d3_value in range(1, 10):  # 3つめの0でない数を何にするか
                    # 数を作る
                    S = ['0'] * N_digit
                    S[0] = str(N)[0]
                    S[d2_position] = str(d2_value)
                    S[d3_position] = str(d3_value)
                    S = int(''.join(S))

                    ans += (S <= N)

print(ans)
