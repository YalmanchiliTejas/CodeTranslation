n = int(input())
k = int(input())
R = len(str(n))
r = R - 1
q = 0
num = [0] * 4
index = [0] * 4
s = str(n)
for i in range(R):
    if s[i] != "0":
        num[q] = int(s[i])
        index[q] = i
        q += 1
    if q == 4:
        break

if k == 1:
    ans = 9 * r + num[0]
elif k == 2:
    ans = 81 * r * (r-1) // 2
    if num[1] != 0:
        pass
    else:
        num[0] -= 1
        num[1] = 9
        index[1] = 1
    ans += 9 * (R - 1) * (num[0] - 1) + num[1] + 9 * (R - index[1] - 1)
elif k == 3:
    ans = 243 * r * (r-1) * (r-2) // 2
    if num[2] != 0:
        pass
    elif num[1] != 0:
        num[1] -= 1
        index[2] = index[1] + 1
        num[2] = 9
    else:
        num[0] -= 1
        index = [0, 1, 2]
        num[1], num[2] = 9, 9
    ans += 81 * (R-1)*(R-2)*(num[0]-1)//2 + 9 * (R - index[1] - 1) * (num[1] - 1)
    ans += 81 * (R-index[1]-1)*(R-index[1]-2) // 2
    ans += 9 * (R - index[2] - 1) + num[2]
print(ans)