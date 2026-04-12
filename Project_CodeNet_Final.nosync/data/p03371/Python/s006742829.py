A, B, C, X, Y = list(map(int, input().split()))

# A 1枚、B 1枚を2C円で買うと捉え直す。
# ピザは、最大でも10**5枚（A, Bそれぞれに対して）
# A, Bのセットを、1~10**セットまで動かして一番安い組を考える

cheapest = float("inf")

for i in range(max(X, Y) + 1):

    price = 2 * C * i + A * max(0, X - i) + B * max(0, Y - i)

    cheapest = min(cheapest, price)

print(cheapest)
