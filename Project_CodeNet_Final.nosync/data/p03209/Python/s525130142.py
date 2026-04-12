n, x = map(int, input().split())

x -= 1

length = [1]
n_p = [1]
for i in range(n):
    length.append(length[-1] * 2 + 3)
    n_p.append(n_p[-1] * 2 + 1)

length = length[::-1]
n_p = n_p[::-1]

ans = 0
for i in range(len(length)):

    if i == len(length) - 1:
        if x >= 0:
            ans += 1
    else:
        # print(x, ans, length[i+1])
        if x == length[i+1] + 1:
            ans += n_p[i+1] + 1
            break
        elif x == length[i+1]:
            ans += n_p[i+1]
            break
        elif x < length[i+1]:
            x -= 1
        else:
            x -= (length[i+1] + 2)
            ans += n_p[i+1] + 1

print(ans)
