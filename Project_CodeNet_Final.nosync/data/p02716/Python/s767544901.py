n = int(input())
A = list(map(int, input().split()))

pick_DP = [-float('INF')] * n
unpick_DP = [-float('INF')] * n
pick_DP[0] = 0
unpick_DP[0] = 0

for i, a in enumerate(A, 1):
    mini = (i-1)//2 - 1
    if mini <= 0:
        mini = 1
    maxi = (i+1)//2

    temp = []
    for num in range(mini, maxi+1):
        temp.append(pick_DP[num])
        pick_DP[num] = max(unpick_DP[num-1] + a, pick_DP[num])

    for num, pre_pick in enumerate(temp, mini):
        if unpick_DP[num] < pre_pick:
            unpick_DP[num] = pre_pick

print(max(pick_DP[n//2], unpick_DP[n//2]))