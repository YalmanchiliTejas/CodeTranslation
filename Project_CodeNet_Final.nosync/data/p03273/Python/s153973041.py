""" AtCoder """

H, W = map(int, input().split())

a = [input() for _ in range(H)]

ans = []
ans = []
ans_len = 0

for i in range(H):
    if a[i].count('#') != 0:
        ans.append(a[i])
        ans_len += 1

for t in range(W):
    for i in range(W):
        check = True
        for j in range(ans_len):
            if ans[j][i] == '#':
                check = False
                break
        if check:
            tmp = ans
            ans = []
            for j in range(ans_len):
                ans.append(tmp[j][:i] + tmp[j][i+1:])
            W -= 1
            break

for i in range(ans_len):
    print(ans[i])
