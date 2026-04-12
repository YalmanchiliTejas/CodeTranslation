def c_dubious_document(N, S):
    from collections import defaultdict, Counter
    # 各文字列の中に共通した文字はあるか？
    d = [None for _ in range(N)]  # i番は文字列Siに出現する文字の一覧と個数
    for i, s in enumerate(S):
        d[i] = Counter(s)

    common = defaultdict(str)  # 文字列の中で共通する文字の一覧と個数
    for c in range(ord('a'), ord('z') + 1):
        c = chr(c)
        low = float('inf')
        for i in range(N):
            low = min(low, d[i][c])
        if low != 0:
            common[c] = low
    common = sorted(common.items())  # キーでソート(いらないかも)

    ans = ''
    for c, v in common:
        ans += c * v
    return ans

N = int(input())
S = [input().strip() for _ in range(N)]
print(c_dubious_document(N, S))