from collections import deque

# 下右1マスを検索するために必要とする
dis_x = [1, 0]
dis_y = [0, 1]

# 迷路の縦幅,横幅
max_h, max_w = map(int, input().split())

s = []
av_count = 0
for _ in range(max_h):
    line = input()
    av_count += line.count("#")
    # 横1マスを壁でPadding. これでindex out of boundを防ぐ
    s.append(list(".{}.".format(line)))

# 縦1マスを壁でPadding. これでindex out of boundを防ぐ
s = [list("." * (max_w + 2))] + s + [list("." * (max_w + 2))]

# 迷路と同じサイズの距離表を作成.
# 値が0 -> 未訪問, それ以外 -> スタート地点からそれまでの距離となる
dist = [ [0] * (max_w + 2) for _ in range(max_h+2)]

# キューにスタート地点をプッシュ
que = deque([(1, 1)])

# キューに値が格納されている間
while que:
    # 先頭の値を取り出す
    h, w = que.popleft()

    for i in range(2):
        # 移動距離
        dx, dy = dis_x[i], dis_y[i]
        if s[h+dy][w+dx] == '#' and dist[h+dy][w+dx] == 0:
            # ここまでの距離+1して訪問済みに
            dist[h+dy][w+dx] = dist[h][w] + 1
            # キューに加える -> (h+dy, w+dx) を起点にまた上下左右4マスをチェックする,という意味
            que.append((h+dy, w+dx))
            break

dist[1][1] = 1

dis = 0
for line in dist:
  dis += len(list(filter(lambda x : x != 0, line)))

print("Possible" if av_count == dis else "Impossible")
