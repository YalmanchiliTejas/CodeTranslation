h, w = map(int, input().split())

ans = []
for i in range(h):
    temp = input()
    if '#' not in temp:
        continue
    ans.append(temp)

for i in reversed(range(w)):
    if ans[0][i] == '.':
        flag = True
        for j in range(len(ans)):
            if ans[j][i] != '.':
                flag = False
                break

        if flag:
            for j in range(len(ans)):
                ans[j] = ans[j][:i] + (ans[j][i+1:len(ans[j])] if i+1 < len(ans[j]) else '')

for i in range(len(ans)):
    print(ans[i])
