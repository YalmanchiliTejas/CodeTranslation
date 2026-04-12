import sys
IS = lambda: sys.stdin.readline().rstrip()
II = lambda: int(IS())
MII = lambda: list(map(int, IS().split()))

def main():
    h, w = MII()
    aa = [IS() for _ in range(h)]
    aa_w = [a for a in aa if '.'*w != a]
    aa_w_t = [''.join(list(a)) for a in zip(*aa_w)]
    w = len(aa_w_t[0])
    aa_w = [a for a in aa_w_t if '.'*w != a]
    aa_w_t = [''.join(list(a)) for a in zip(*aa_w)]
    aa_w_t = [''.join(list(a)) for a in zip(*aa_w)]
    for a in aa_w_t: print(a)


if __name__ == '__main__':
    main()
