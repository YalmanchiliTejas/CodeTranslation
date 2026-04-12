options = [(0, 0), (0, 1), (1, 0), (1, 1)]


def judge(n, s):
    res = [None] * n
    for op in options:
        res[-1], res[0] = op
        s_num = list(map(lambda a: 0 if a == 'o' else 1, s))
        for i in range(n):
            res[(i + 1) % n] = res[i] ^ s_num[i] ^ res[i - 1]
        if (res[-1], res[0]) == op:
            print(''.join(map(lambda a: 'S' if a == 0 else 'W', res)))
            exit()

n = int(input())
s = input()
judge(n, s)
print(-1)
