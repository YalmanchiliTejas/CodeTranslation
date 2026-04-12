N, X, M = map(int, input().split())

a = X
path = [a]  # path: 数列Ai
done = set([a])  # done: 既に登場したAiの項
while True:
    na = pow(a, 2, M)
    if na in done:
        s = path.index(na)  # 繰り返しが始まる箇所
        break
    else:
        path.append(na)
        done.add(na)
        a = na

if N < s + 1:  # N項目がループが始まる箇所よりも前の場合
    ans = sum(path[:N])
else:
    rest = N - s  # rest: ループに入った後の項目数
    x, y = divmod(rest, len(path) - s)  # x: ループを回る回数, y: 最後の1週に満たない項数

    ans = sum(path[:s])  # ループに入る前の和
    ans += sum(path[s:]) * x  # ループを繰り返す部分の和
    ans += sum(path[s: s + y])  # ループの最後の1週に満たない部分の和
print(ans)