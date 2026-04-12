import itertools

N, M = map(int, input().split())
G = [[] * (N + 1)for _ in range(N + 1)]
for _ in range(M):
    a, b = map(int, input().split())
    G[a].append(b)
    G[b].append(a)

l = range(2, N + 1)

ans = 0

for p in itertools.permutations(l):
    # 試す順列を作る
    nums = [1]
    for n in p:
        nums.append(n)

    flag = True

    for i in range(N - 1):
        if nums[i + 1] in G[nums[i]]:
            continue
        else:
            flag = False
            break
    if flag == True:
        ans += 1

print(ans)
