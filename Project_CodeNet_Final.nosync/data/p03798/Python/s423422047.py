from itertools import product

N = int(input())
s = input()

answer = [''] * N

for i, j in product(['S', 'W'], repeat=2):
    answer[0] = i
    answer[1] = j
    for k in range(2, N):
        if answer[k - 1] == 'S':
            if s[k - 1] == 'o':
                answer[k] = answer[k - 2]
            else:
                if answer[k - 2] == 'W':
                    answer[k] = 'S'
                else:
                    answer[k] = 'W'
        else:
            if s[k - 1] == 'x':
                answer[k] = answer[k - 2]
            else:
                if answer[k - 2] == 'W':
                    answer[k] = 'S'
                else:
                    answer[k] = 'W'

    for k in [-1, 0]:
        if answer[k] == 'S':
            if s[k] == 'o':
                if answer[k - 1] != answer[k + 1]:
                    break
            else:
                if answer[k - 1] == answer[k + 1]:
                    break
        else:
            if s[k] == 'x':
                if answer[k - 1] != answer[k + 1]:
                    break
            else:
                if answer[k - 1] == answer[k + 1]:
                    break
    else:
        print(''.join(answer))
        exit()

print(-1)