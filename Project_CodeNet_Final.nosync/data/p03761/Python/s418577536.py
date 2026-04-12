N = int(input())
S = [input() for _ in range(N)]

abc = 'abcdefghijklmnopqrstuvwxyz'

ans = ''
cnt = 0

for a in abc:
    cnt = 100
    for s in S:
        cnt = min(cnt, s.count(a))

    ans += a*cnt
print(ans)
