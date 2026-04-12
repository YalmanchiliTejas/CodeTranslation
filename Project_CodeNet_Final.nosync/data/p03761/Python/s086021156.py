n = int(input())
S = [0] * n
for i in range(n):
    S[i] = list(input())

count = [[0] * 27 for _ in range(n)]

alpha2num = lambda c: ord(c) - ord('A') + 1
num2alpha = lambda c: chr(c+64)


for i in range(n):
    for j in range(len(S[i])):
        tmp = alpha2num(S[i][j].upper())
        count[i][tmp] += 1

#print(count)


count_min = [0] * 27
for i in range(27):
    tmp = 100
    for j in range(n):
        tmp = min(tmp, count[j][i])
    count_min[i] = tmp

#print(count_min)

ans = ''
for i in range(1,27):
    ans += num2alpha(i).lower() * count_min[i]

print(ans)