N = int(input())
S = list(input())

def output(lst):
    map_lst = map(str, lst[:-1])
    s = ''.join(map_lst)
    print (s.replace('0', 'S').replace('1', 'W'))
    return

# 0: 羊、1: 狼
for a in range(2):
    for b in range(2):
        lst = [-1] * (N + 1)
        lst[0] = a
        lst[1] = b
        for i in range(1, N):
            if S[i] == 'o':
                flag = True
            else:
                flag = False

            if flag == (lst[i] == 0):
                lst[i + 1] = lst[i - 1]
            else:
                lst[i + 1] = 1 - lst[i - 1]
        if lst[0] == lst[-1]: #最初の仮定が成り立っているかどうか
            if (S[0] == 'o') == (lst[0] == 0):
                if lst[1] == lst[N - 1]:
                    output(lst)
                    exit()
            else:
                if lst[1] != lst[N - 1]:
                    output(lst)
                    exit()

        # print (lst)

print (-1)