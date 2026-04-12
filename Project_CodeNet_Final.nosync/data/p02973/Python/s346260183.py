import bisect

N = int(input())
A = [int(input()) for _ in range(N)]


colors = []

#後ろから見ていく
for i,n in enumerate(list(reversed(A))):
    # 一つ目はとりあえずなんか一色ぬる
    if i == 0:
        colors.append(n)
    else:
        #二つ目以降は、各色の最小値のなかで、今見ているのより小さいものがあればそれを置き換える
        #ここをbisect_leftにすると、colorsの中で同じ最小値があるときにinsertが必要なので遅い
        # 「各色の最小値集合の最小値と置き換える」を繰り返すので、最小値集合の最大より大きいなら最後に追加
        idx = bisect.bisect_right(colors, n)
        if idx == len(colors):
            colors.append(n)
        else:
            colors[idx] = n

print(len(colors))