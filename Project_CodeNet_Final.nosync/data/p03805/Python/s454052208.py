from itertools import repeat, permutations


if __name__ == '__main__':
    n, m = map(int, input().split())    # 2≦N≦8    nが小さいので列挙でもいけるか?
    # 0≦M≦N(N−1)⁄2    全ての頂点が結ばれている場合もあり得る。
    edges = [list(repeat(False, n)) for i in range(n)]
    for i in range(m):
        a, b = map(int, input().split())
        a -= 1      # 0オリジン
        b -= 1
        edges[a][b] = True
        edges[b][a] = True
    # print(edges)
    # 末端(1本しか道のない頂点)の数で分類すれば高速化するが、
    # 末端のないケースが通るなら場合分けしなくてもTLEしないはず。
    result = 0      # 結果格納用
    # 出発は頂点1(コード内の番号は0)なので、それ以外についてリストする。
    for order_iterable in permutations(range(1, n)):
        order = [0] + list(order_iterable)
        # orderの隣同士の間に辺が存在することが、到達可能の条件
        if all([edges[order[i - 1]][order[i]] for i in range(1, n)]):
            result += 1     # 計数
    print(result)
