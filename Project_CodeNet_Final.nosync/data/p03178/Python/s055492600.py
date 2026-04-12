k = input()
d = int(input())
n = len(k)
mod = 10**9 + 7

MOD = [[0] * 10 for i in range(n)]
# for i in range(1, 10):
#     MOD[0][i] = (MOD[0][i-1] + 1) % d
# for i in range(1, n):
#     for j in range(10):
#         MOD[i][j] = (MOD[i-1][j] * 10) % d

for i in range(n):
    for j in range(10):
        MOD[i][j] = j % d

D = [0] * d
h = 0
for i in range(int(k[0])):
    D[MOD[n-1][i]] += 1
h = MOD[n-1][int(k[0])]

for i in range(1, n):
    # print(D)
    DN = [0] * d
    for j in range(10):
        for l in range(d):
            DN[(l + MOD[n-1-i][j]) % d] = (DN[(l + MOD[n-1-i][j]) % d] + D[l]) % mod
    for j in range(int(k[i])):
        DN[(h + MOD[n-1-i][j]) % d] = (DN[(h + MOD[n-1-i][j]) % d] + 1) % mod
    h = (h + MOD[n-1-i][int(k[i])]) % d
    D = DN[:]
# print(D)

D[h] += 1
# print(D)
print((D[0] - 1) % mod)