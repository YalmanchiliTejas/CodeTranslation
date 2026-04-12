#!/usr/bin/env python3
import sys
sys.setrecursionlimit(300000)


def solve(N: int, s: str):
    def is_valid(v, prev, cur, nex):
        if (v == 'o' and nex == (prev + cur) % 2 or
            v == 'x' and nex == (prev + cur + 1) % 2):
            return True
        return False

    r = None
    for c0 in [0, 1]:
        for c1 in [0, 1]:
            ret = [0] * N
            ret[0] = c0
            ret[1] = c1
            for i in range(1, N - 1):
                if s[i] == 'o':
                    ret[i + 1] = (ret[i - 1] + ret[i]) % 2
                else:
                    ret[i + 1] = (ret[i - 1] + ret[i] + 1) % 2
            if (is_valid(s[N - 1], ret[N - 2], ret[N - 1], ret[0]) and 
                is_valid(s[0], ret[N - 1], ret[0], ret[1])):
                r = ['W' if t else 'S' for t in ret]
                #print(c0, c1, r)
                break
    if r:
        print(''.join(r))
    else:
        print(-1)
    return


def main():
    def iterate_tokens():
        for line in sys.stdin:
            for word in line.split():
                yield word
    tokens = iterate_tokens()
    N = int(next(tokens))  # type: int
    s = next(tokens)  # type: str
    solve(N, s)

if __name__ == '__main__':
    main()
