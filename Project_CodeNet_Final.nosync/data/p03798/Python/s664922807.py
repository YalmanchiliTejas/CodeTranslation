N = int(input())
S = input()
for p in ("SS", "SW", "WS", "WW"):  # N-1と0
    ans = p[1]
    ip = p
    for i in range(N):
        if S[i] == "o":
            if p[0] == p[1]:
                p = p[1] + "S"
            else:
                p = p[1] + "W"
        else:
            if p[0] == p[1]:
                p = p[1] + "W"
            else:
                p = p[1] + "S"
        ans += p[-1]
    if ans[-2:] == ip:
        print(ans[:-1])
        exit()
print(-1)
