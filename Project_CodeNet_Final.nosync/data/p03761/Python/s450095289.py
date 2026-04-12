def count(s):
    res = {}
    for ch in s:
        if not ch in res:
            res[ch] = 0
        res[ch] += 1
    return res

def run():
    n = int(raw_input())
    S = [sorted(raw_input()) for i in range(n)]
    U = [count(s) for s in S]
    ans = ""
    for ch in set(S[0]):
        num = min([(u[ch] if ch in u else 0) for u in U])
        if num > 0:
            ans += ch * num
    return "".join(sorted(ans))
print run()