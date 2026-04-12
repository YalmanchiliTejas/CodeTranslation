n = list(reversed(input()))
k = int(input())
dp1 = [1] + [0] * 3
dp2 = [1] + [0] * 3
for i in range(len(n)):
    newdp1 = [0] * 4
    newdp2 = [0] * 4
    for j in range(4):
        newdp2[j] += dp2[j]
        if j > 0:
            newdp2[j] += dp2[j - 1] * 9
        d = int(n[i])
        if d == 0:
            newdp1[j] += dp1[j]
        else:
            newdp1[j] += dp2[j]
        if j > 0:
            if d > 0:
                newdp1[j] += dp1[j - 1]
                newdp1[j] += dp2[j - 1] * (d - 1)
    dp1 = newdp1
    dp2 = newdp2
print(dp1[k])
