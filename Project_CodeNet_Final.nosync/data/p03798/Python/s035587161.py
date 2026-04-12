def is_ok(idx):
    flg = False
    bf = (idx - 1) % N
    af = (idx + 1) % N

    if t[idx] == 'S':
        if s[idx] == 'o':
            if t[af] == t[bf]:
                flg = True
        else:
            if t[af] != t[bf]:
                flg = True
    else:
        if s[idx] == 'x':
            if t[af] == t[bf]:
                flg = True
        else:
            if t[af] != t[bf]:
                flg = True
    return flg


N = int(input())
s = input()

ans = ['-1']
flg = False
for first in 'SW':
    for second in 'SW':
        t = [None for _ in range(N)]
        t[0] = first
        t[1] = second
        for i, ss in enumerate(s):
            if i <= 1: continue

            if t[i - 1] == 'S':
                if s[i - 1] == 'o':
                    t[i] = t[i - 2]
                else:
                    t[i] = 'W' if t[i - 2] == 'S' else 'S'
            else:
                if s[i - 1] == 'o':
                    t[i] = 'W' if t[i - 2] == 'S' else 'S'
                else:
                    t[i] = t[i - 2]
            # i番目の動物の種別を決める
        # print(t)

        if is_ok(0) and is_ok(N - 1):
            flg = True
            ans = t
            break

    if flg: break

print(''.join(ans))
