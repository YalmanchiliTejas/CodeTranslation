def c_dubious_document(N, S):
    import collections
    import string
    # 各文字列の中に共通した文字はあるか？
    d = [None for _ in range(N)]  # i番は文字列Siに出現する文字の一覧と個数
    for i, s in enumerate(S):
        d[i] = collections.Counter(s)

    common = collections.defaultdict(str)  # 文字列の中で共通する文字の一覧と個数
    for c in string.ascii_lowercase:
        low = float('inf')
        for i in range(N):
            low = min(low, d[i][c])
        if low != 0:
            common[c] = low
    common = sorted(common.items())

    ans = ''
    for c, v in common:
        ans += c * v
    return ans

N = int(input())
S = [input().strip() for _ in range(N)]
print(c_dubious_document(N, S))