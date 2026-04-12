N = int(input())
AA = [int(input()) for _ in range(N)]
AA.sort()
AF = AA[:N//2]
AL = AA[N//2:]
ans = 0
if N % 2 == 0:
    ans = sum(AL)*2 - AL[0] - sum(AF)*2 + AF[-1]
else:
    ans1 = sum(AL)*2 - sum(AF)*2 - sum(AL[0:2])
    ans2 = sum(AL)*2 - sum(AF)*2 - 3 * AL[0] + AF[-1]
    ans = max(ans1, ans2)


print(ans)