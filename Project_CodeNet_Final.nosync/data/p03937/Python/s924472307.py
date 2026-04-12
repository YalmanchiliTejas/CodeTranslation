from collections import deque


def main():
    H, W = list(map(int, input().split()))
    A = [list(input()) for _ in range(H)]
    # 「右or下のみ移動可」で深さ優先探索
    # 移動時、該当マスを左上角とする長方形領域以外に未訪問の '#' があったらNG
    # ゴールに到達できなくてもNG
    que = deque()
    que.append((0, 0))
    ok = False
    while len(que) > 0:
        h, w = que.pop()
        A[h][w] = '.'
        if (h, w) == (H - 1, W - 1):
            ok = True
            break
        # 横方向
        next_h, next_w = h, w + 1
        if next_w < W and A[next_h][next_w] == '#':
            exist_unvisited = False
            for hh in range(next_h, H):
                if A[hh][w] == '#':
                    exist_unvisited = True
                    break
            if exist_unvisited:
                break
            que.append((next_h, next_w))
            continue
        # 縦方向
        next_h, next_w = h + 1, w
        if next_h < H and A[next_h][next_w] == '#':
            exist_unvisited = False
            for ww in range(next_w, W):
                if A[h][ww] == '#':
                    exist_unvisited = True
                    break
            if exist_unvisited:
                break
            que.append((next_h, next_w))
            continue
    if ok:
        print('Possible')
    else:
        print('Impossible')


if __name__ == '__main__':
    main()
