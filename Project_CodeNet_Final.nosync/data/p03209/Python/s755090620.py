N, X = map(int, input().split())

f = [[0, 0] for i in range(N + 1)]

# 総数, パティ
f[0] = [1, 1]
for i in range(1, N + 1):
    # print(i)
    f[i][0] = 2 * f[i - 1][0] + 3
    f[i][1] = 2 * f[i - 1][1] + 1
    # print(f[i][0], f[i][1])

"""
for i in range(0, N + 1):
    print(f[i][0], f[i][1])
"""

leftA = 0
leftB = 0

ans = 0

for i in range(N, 0, -1):
    if leftA + 1 == X:
        # finish
        ans = leftB
        break
    elif leftA + 1 + f[i-1][0] == X:
        # finish
        ans = leftB + f[i-1][1]
        break
    elif leftA + 1 + f[i-1][0] > X:
        leftA = leftA + 1
    elif leftA + 1 + f[i-1][0] + 1 == X:
        # finish
        ans = leftB + 1 + f[i-1][1]
        break
    elif leftA + 1 + f[i-1][0] + 1 + f[i-1][0] == X:
        # finish
        ans = leftB + 1 + 2 * f[i-1][1]
        break
    elif leftA + 1 + f[i-1][0] + 1 + f[i-1][0] > X:
        leftA = leftA + 1 + f[i-1][0] + 1
        leftB = leftB + 1 + f[i-1][1]
    elif leftA + 1 + f[i-1][0] + 1 + f[i-1][0] + 1 == X:
        # finish
        ans = leftB + 1 + 2 * f[i-1][1]
        break
    # print(leftA, leftB)

print(ans)