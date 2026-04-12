n = input()
k = int(input())

dp1 = [ [ i+1 for i in range(9) ] for i in range(201)]
dp2 = [ [ 0 for i in range(9) ] for i in range(201)]
dp3 = [ [ 0 for i in range(9) ] for i in range(201)]

for i in range(200):
    for j in range(9):
        if j == 0:
            dp1[i+1][j] = dp1[i][-1] + 1
        else:
            dp1[i+1][j] = dp1[i+1][j-1] + 1

for i in range(200):
    for j in range(9):
        if j == 0:
            dp2[i+1][j] = dp2[i][-1] + 9 * (i)
        else:
            dp2[i+1][j] = dp2[i+1][j-1] + 9 * (i+1)

for i in range(200):
    for j in range(9):
        if j == 0:
            dp2[i+1][j] = dp2[i][-1] + 9 * (i)
        else:
            dp2[i+1][j] = dp2[i+1][j-1] + 9 * (i+1)

for i in range(100):
    for j in range(9):
        if j == 0:
            dp3[i+1][j] = dp3[i][-1] + 81 * i*(i-1)//2
        else:
            dp3[i+1][j] = dp3[i+1][j-1] + 81 * (i+1) * i //2


def solve(s, x):
    if s == "0":
        return 0
    elif s[0] == "0":
        return solve(s[1:], x)

    if x == 1:

        return  dp1[len(s)-1][int(s[0]) - 1]
    elif x == 2:
        if len(s) < 2:
            return 0
        return  dp2[len(s)-1][int(s[0]) - 1] + solve(s[1:], 1)
    elif x == 3:
        if len(s) < 3:
            return 0
        return  dp3[len(s)-1][int(s[0]) - 1] + solve(s[1:], 2)

print(solve(n, k))
