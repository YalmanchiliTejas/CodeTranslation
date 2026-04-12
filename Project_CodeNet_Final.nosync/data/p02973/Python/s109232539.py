import bisect

n = int(input())
a = [int(input()) for _ in range(n)]
# それぞれの色の最大値を入れる筒のリスト
t = [a[-1]]

for i in reversed(a[:-1]):
    # それぞれの色のどの値よりも小さかったとき
    idx = bisect.bisect_left(t, i+1)
    # print(i, idx)
    if idx == len(t):
        t.append(i)
    # 効率的な色の探索
    else:
        t[idx] = i
    # print(t)

print(len(t))