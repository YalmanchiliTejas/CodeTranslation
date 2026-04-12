import sys


def main():
    N = int(input())
    s = list(input())
    s.append(s[0])
    s.insert(0, s[-2])

    init = ((0, 0), (0, 1), (1, 0), (1, 1))
    for i in init:
        p = [0] * (N+2)
        p[0] = i[0]
        p[1] = i[1]
        for j in range(1, N+1):
            if s[j] == "o":
                if p[j] == 0:
                    p[j+1] = p[j-1] ^ 0
                else:
                    p[j+1] = p[j-1] ^ 1
            else:
                if p[j] == 0:
                    p[j+1] = p[j-1] ^ 1
                else:
                    p[j+1] = p[j-1] ^ 0

        if p[0] == p[-2] and p[1] == p[-1]:
            ss = list(map(lambda x: "W" if x == 1 else "S", p[1:N+1]))
            print(''.join(ss))
            sys.exit()
    else:
        print(-1)


main()
