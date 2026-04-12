n = int(input())
s = input()
s += s[0]

is_ans = False
for ans in ['SS', 'SW', 'WS', 'WW']:
    for i in range(1, n+1):
        a_0 = ans[i-1]
        a_1 = ans[i]
        if s[i] == 'o' and a_1 == 'S':
            if a_0 == 'S':
                ans += 'S'
            else:
                ans += 'W'
        elif s[i] == 'x' and a_1 == 'S':
            if a_0 == 'S':
                ans += 'W'
            else:
                ans += 'S'
        elif s[i] == 'o' and a_1 == 'W':
            if a_0 == 'S':
                ans += 'W'
            else:
                ans += 'S'
        else:
            if a_0 == 'S':
                ans += 'S'
            else:
                ans += 'W'
    if ans[-2:] == ans[:2]:
        print(ans[:-2])
        is_ans = True
        break
if not is_ans:
    print(-1)