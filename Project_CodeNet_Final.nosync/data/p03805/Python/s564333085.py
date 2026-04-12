from itertools import permutations

N, M = map(int, input().split())
edge = [list(map(int, input().split())) for _ in range(M)]

ed = list(range(1, N+1))
temp = permutations(ed)

ans = 0

for i in temp:
    flg = True
    if i[0] != 1:
        continue
    else:
        for j in range(1, N):
            a, b = i[j-1], i[j]
            if a > b:
                ab = a
                a = b
                b = ab
            if [a, b] in edge:
                continue
            else:
                flg = False
                break
    if flg:
        ans += 1

print(ans)