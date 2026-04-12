N = int(input())
s = input()
start_pattern = ['SS', 'SW', 'WS', 'WW']
s2 = s+s[0]
for start in start_pattern:
    ans = start
    before = s[0]

    for i, now in enumerate(s2[1:]):
        if i == N-1:
            break
        before_state = ans[i]
        now_state = ans[i+1]
        if now_state == 'S':
            yes = 'o'
            no = 'x'
        else:
            yes = 'x'
            no = 'o'

        if now == yes:
            ans += before_state
        else:
            if before_state == 'S':
                ans += 'W'
            else:
                ans += 'S'
    if ans[0] == ans[-1]:
        ok = False
        if ans[0] == 'S':
            yes = 'o'
        else:
            yes = 'x'
        if s[0] == yes:
            if ans[1] == ans[-2]:
                ok = True
        else:
            if ans[1] != ans[-2]:
                ok = True
        if ok:
            print(ans[:-1])
            exit()
print('-1')
