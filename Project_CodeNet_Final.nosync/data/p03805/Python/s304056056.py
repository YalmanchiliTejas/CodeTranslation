from itertools import permutations
n, m = map(int, input().split())
list_AB = [ list(map(int,input().split(" "))) for i in range(m)]
list_MAP = [[0]*n for _ in range(n)]
list_N = [i for i in range(2, n+1)]

for a, b in list_AB:
    list_MAP[a-1][b-1] = 1
    list_MAP[b-1][a-1] = 1

ans = 0

for l in permutations(list_N, n-1):
    cnt = 0
    p = 1
    q = 0
    for num in l:
        q = num
        cnt += list_MAP[p-1][q-1]
        p = num

    if cnt == n-1:
        ans += 1

print(ans)