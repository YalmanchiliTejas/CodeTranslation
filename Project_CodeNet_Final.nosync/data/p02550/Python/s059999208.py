N, x, M = [int(a) for a in input().split()]

# Let g(i) = x ^ (2^i) mod M
g = [x] + [0] * M
ginv = [-1] * (M + 1)
ginv[x] = 0
partSum = [x] + [0] * (M + 1)     # partSum[-1] = 0 となるようにダミーを追加

for i in range(1, M + 1):
    g[i] = g[i - 1] * g[i - 1] % M
    if ginv[g[i]] >= 0:  # detected cycle
        iStart = ginv[g[i]]
        cycleSum = partSum[i - 1] - partSum[iStart - 1]
        cycleLen = i - iStart

        numCycle = (N - 1 - (i - 1)) // cycleLen
        remCycle = (N - 1 - (i - 1)) % cycleLen
        ans = partSum[i - 1] + cycleSum * numCycle + partSum[iStart + remCycle - 1] - partSum[iStart - 1]
        break
    else:
        ginv[g[i]] = i
        partSum[i] = partSum[i - 1] + g[i]

print(ans)