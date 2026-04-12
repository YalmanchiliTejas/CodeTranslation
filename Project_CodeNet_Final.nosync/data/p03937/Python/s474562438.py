def main():
    import sys
    from collections import deque
    input = sys.stdin.readline
    H, W = [int(x) for x in input().strip().split()]
    M = [''] * H
    f = False
    for h in range(H):
        M[h] = list(input().strip())
        if '#' in M[h]:
            f = True
    s = deque([(0, 0)])
    if not f:
        print('Impossible')
        return
    if M[0][0] == '.':
        print('Impossible')
        return
    M[0][0] = '.'
    while s:
        (h, w) = s.popleft()
        if h + 1 < H:
            if M[h+1][w] == '#':
                M[h+1][w] = '.'
                s.append((h+1, w))
                continue
        if w + 1 < W:
            if M[h][w+1] == '#':
                M[h][w+1] = '.'
                s.append((h, w+1))

    for h in range(H):
        if '#' in M[h]:
            print('Impossible')
            return
    else:
        print('Possible')
        return

if __name__ == '__main__':
    main()