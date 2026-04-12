import sys
N = int(input())
s = input()
not_sw = {'S':'W', 'W':'S'}

for sw1 in ['S', 'W']:
    for sw2 in ['S', 'W']:
        flag = True
        ans = [''] * (N+1)
        ans[0] = sw1
        ans[-1] = sw1
        if (s[0] == 'o' and ans[0] == 'S')  or (s[0] == 'x' and ans[0] == 'W'):
            ans[1] = sw2
            ans[-2] = sw2
        elif (s[0] == 'x' and ans[0] == 'S')  or (s[0] == 'o' and ans[0] == 'W'):
            ans[1] = not_sw[sw2]
            ans[-2] = sw2
        for i in range(1, N-2):
            if (s[i] == 'o' and ans[i] == 'S')  or (s[i] == 'x' and ans[i] == 'W'):
                ans[i+1] = ans[i-1]
            elif (s[i] == 'x' and ans[i] == 'S')  or (s[i] == 'o' and ans[i] == 'W'):
                ans[i+1] = not_sw[ans[i-1]]
        for i in range(N-2, N):
            if (s[i] == 'o' and ans[i] == 'S')  or (s[i] == 'x' and ans[i] == 'W'):
                if ans[i+1] != ans[i-1]:
                    flag = False
            elif (s[i] == 'x' and ans[i] == 'S')  or (s[i] == 'o' and ans[i] == 'W'):
                if ans[i+1] != not_sw[ans[i-1]]:
                    flag = False
        if flag:
            print(''.join(ans[:-1]))
            sys.exit()
print(-1)
