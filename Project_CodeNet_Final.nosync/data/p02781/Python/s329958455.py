def main():

    N = int(input())
    K = int(input())
    S = str(N)

    if K == 1:
        v = (len(S) - 1) * 9
        v += int(S[0])
        return v
    if K == 2:
        v = (len(S)-1) * (len(S)-2) * 9 * 9 // 2
        v += (int(S[0]) - 1) * 9 * (len(S)-1)
        u = int(S[0]) * pow(10, len(S)-1)
        for j in range(len(S)-1):
            for k in range(1, 10):
                if u + k * pow(10, j) <= N:
                    v += 1
        return v
    if K == 3:
        v = (len(S)-1) * (len(S)-2) * (len(S)-3) * 9 * 9 * 9 // 6
        v += (int(S[0]) - 1) * 9 *9 * (len(S)-1) * (len(S)-2) // 2
        u = int(S[0]) * pow(10 ,len(S)-1)
        ps = [1]
        for i in range(len(S)+1):
            ps.append(ps[-1] * 10)
        for j1 in range(len(S)-1):
            for j2 in range(j1):
                for k1 in range(1, 10):
                    for k2 in range(1, 10):
                        if u + k1 * ps[j1] + k2 * ps[j2] <= N:
                            v += 1
        return v


if __name__ == '__main__':
    print(main())