N = int(input())
S = input()


def check(ans):
    for i in range(1, N - 1):
        if (ans[i] == 0) == (S[i] == 'o'):
            ans += [ans[i - 1]]
        else:
            ans += [1 - ans[i - 1]]
    if ((S[0] == 'o') == (ans[0] == 0)) != (ans[1] == ans[-1]):
        return
    if ((S[-1] == 'o') == (ans[-1] == 0)) != (ans[-2] == ans[0]):
        return
    print(*['W' if _ else 'S' for _ in ans], sep='')
    exit()


check([0, 0])
check([0, 1])
check([1, 0])
check([1, 1])
print(-1)
