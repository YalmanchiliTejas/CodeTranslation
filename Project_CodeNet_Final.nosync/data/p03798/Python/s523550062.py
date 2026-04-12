N = int(input())
S = input().replace('o', '0').replace('x', '1')
S = list(map(int, S))

for pattern in [[0, 0], [0, 1], [1, 0], [1, 1]]:
    for s in S[1:]:
        if pattern[-2] ^ pattern[-1] ^ s == 0:
            pattern.append(0)
        else:
            pattern.append(1)

    pattern = pattern[:-1]
    for i, s in enumerate(S):
        if pattern[i - 1] ^ pattern[(i + 1) % N] ^ s != pattern[i]:
            break
    else:
        pattern = ''.join(map(str, pattern)).replace('0', 'S').replace('1', 'W')
        print(*pattern, sep='')
        break
else:
    print(-1)
