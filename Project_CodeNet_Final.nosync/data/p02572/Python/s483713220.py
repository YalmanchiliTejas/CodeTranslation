n = int(input())
ai = list(map(int, input().split()))

# n=3
# ai = np.array([1, 2, 3])

# ai = ai[np.newaxis, :]
# 
# ai2 = ai.T.dot(ai)
# ai2u = np.triu(ai2, k=1)
# 
# s = ai2u.sum()


l = len(ai)

integ = [ai[0]] * len(ai)
for i in range(1, len(ai)):
    integ[i] = integ[i-1] + ai[i]

s = 0
for j in range(l):
    this_s = integ[-1] - integ[j]
    s += ai[j] * this_s

ans = s % (1000000000 + 7)

print(ans)
