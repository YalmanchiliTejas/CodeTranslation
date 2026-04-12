N = int(input())
S = list(map(int, input().replace('o', '0').replace('x', '1')))

for p in [[0, 0], [0, 1], [1, 0], [1, 1]]:
    for s in S[1:]:
        if p[-1] ^ p[-2] ^ s == 1:
            p.append(1)
        else:
            p.append(0)

    if (p[0] == p[-1]) and (p[-2] ^ p[-3] ^ p[0] ^ S[-1] == 0) and (p[0] ^ p[-2] ^ p[1] ^ S[0] == 0):
        print(''.join(map(str, p[:-1])).replace('0', 'S').replace('1', 'W'))
        break
else:
    print(-1)
