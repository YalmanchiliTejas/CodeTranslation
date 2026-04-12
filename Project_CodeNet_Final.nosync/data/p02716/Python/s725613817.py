n = int(input())
A = list(map(int, input().split()))

pick_DP = [-float('INF')] * (n//2 + 2)
unpick_DP = [-float('INF')] * (n//2 + 2)
pick_DP[0] = 0
unpick_DP[0] = 0

for i, a in enumerate(A, 1):
    mini = (i-1)//2 - 1
    if mini <= 0:
        mini = 1
    maxi = (i+1)//2

    for num in range(maxi, mini-1, -1):
        if unpick_DP[num] < pick_DP[num]:
            unpick_DP[num] = pick_DP[num]
        pick_DP[num] = max(unpick_DP[num-1] + a, pick_DP[num])

print(max(pick_DP[n//2], unpick_DP[n//2]))