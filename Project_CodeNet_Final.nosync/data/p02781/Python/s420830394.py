N = input()
K = int(input())

l = len(N)

nozero = [0]*l
if N[0] != "0":
    nozero[0] = 1

for i in range(1, l):
    nozero[i] = nozero[i-1]
    if N[i] != "0":
        nozero[i] += 1 

dp0 = [[0]*2 for _ in range(l)]
dp1 = [[0]*2 for _ in range(l)]
dp2 = [[0]*2 for _ in range(l)]
dp3 = [[0]*2 for _ in range(l)]

for i in range(l):
    dp0[i][0] = 1

def dp(K):
    dps = [dp0, dp1, dp2, dp3]
    return dps[K]

dp(1)[0][0] = int(N[0])

for k in range(1, K+1):
    for i in range(l-1):
        if nozero[i] == k:
            dp(k)[i+1][0] = 1
        elif nozero[i] == k-1:
            dp(k)[i+1][0] = int(N[i+1])
        else:
            dp(k)[i+1][0] = 0
            
        if nozero[i] == k-1:
            dp(k)[i+1][1] += (sum(dp(k-1)[i])-1)*9
        else:
            dp(k)[i+1][1] += sum(dp(k-1)[i])*9

            
        if nozero[i] == k:
            dp(k)[i+1][1] += (sum(dp(k)[i])-1)*1
        else:
            dp(k)[i+1][1] += sum(dp(k)[i])*1

print(sum(dp(K)[l-1]))