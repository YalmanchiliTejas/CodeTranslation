import sys
import collections

sys.setrecursionlimit(10 ** 8)

input = sys.stdin.readline


def main():
    H, W = [int(x) for x in input().split()]
    A = [input().strip() for _ in range(H)]

    q = collections.deque()

    q.append((0, 0))
    v = set()
    v.add((0, 0))

    while q:
        c = q.popleft()

        cnt = 0
        for nj, ni in [[0, 1], [1, 0], [-1, 0], [0, -1]]:
            if 0 <= nj + c[0] < H and 0 <= ni + c[1] < W:
                if (nj + c[0], ni + c[1]) in v or A[nj + c[0]][ni + c[1]] == '.':
                    continue
                cnt += 1
                if nj < 0 or ni < 0:
                    print("Impossible")
                    return
                q.append((nj + c[0], ni + c[1]))
                v.add((nj + c[0], ni + c[1]))

        if cnt > 1:
            print("Impossible")
            return

    print("Possible")



if __name__ == '__main__':
    main()
