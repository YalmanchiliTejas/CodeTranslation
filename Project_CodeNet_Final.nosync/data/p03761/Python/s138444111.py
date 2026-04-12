N = int(input())
S = []
for i in range(N):
    s = list(input())
    S.append(s)
ans = []
for az in "abcdefghijklmnopqrstuvwxyz":
    cnt_min = float("inf")
    for i in range(N):
        cnt = S[i].count(az)
        if cnt < cnt_min:
            cnt_min = cnt
    for i in range(cnt_min):
        ans.append(az)
print("".join(ans))