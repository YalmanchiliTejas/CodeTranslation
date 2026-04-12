n = int(input())
S = [input() for _ in range(n)]

ans = ''
alph = 'abcdefghijklmnopqrstuvwxyz'
for i, ch in enumerate(alph):
    cnt = 10e9
    for ss in S:
        cnt = min(cnt,ss.count(ch))
    ans += ch*cnt

print(ans)