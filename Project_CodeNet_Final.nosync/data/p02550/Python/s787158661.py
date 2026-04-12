def main():
    N, X, M = list(map(int, input().split()))
    visited = [0] * M
    a = X
    path = list()
    while visited[a] == 0:
        visited[a] = 1
        path.append(a)
        a = (a**2) % M
    # ここのaは2度目なのでループの始端。
    # ループに入るまでの項数とループ長を求める。
    offset_size = 0
    for p in path:
        if p == a:
            break
        offset_size += 1
    loop_size = len(path) - offset_size
    # 後は、始端＋ループ＋最終ループに分けて、各値が何回出てくるか計算
    count = [0] * M
    n = 0
    # 始端
    for p in path[:offset_size]:
        count[p] += 1
        n += 1
        if n == N:
            break
    # ループ
    count_loop = (N - n) // loop_size
    for p in path[offset_size:]:
        count[p] += count_loop
        n += count_loop
    # 最後
    for p in path[offset_size:]:
        if n == N:
            break
        count[p] += 1
        n += 1
    print(sum([m * c for m, c in enumerate(count)]))


if __name__ == '__main__':
    main()