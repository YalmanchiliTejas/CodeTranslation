N = int(input())
S = [list(input()) for _ in range(N)]

j = -1
ans = []
cnt = 0
for al in [chr(i) for i in range(97, 123)]:
    j += 1
    cnt_min = 100
    for i in range(N):
        cnt = 0
        while al in S[i]:
            S[i].remove(al)
            cnt += 1
        cnt_min = min(cnt_min, cnt)
    ans += [al] * cnt_min
ans = ''.join(ans)
print(ans)
