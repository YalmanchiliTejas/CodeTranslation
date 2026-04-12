from collections import deque


def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    A.sort()
    ans = 0
    B = deque(A)
    edge = [B.popleft()] * 2
    while len(B):
        a = abs(edge[0] - B[0])
        b = abs(edge[0] - B[len(B) - 1])
        c = abs(edge[1] - B[0])
        d = abs(edge[1] - B[len(B) - 1])
        if max(a, b, c, d) == a:
            edge[0] = B.popleft()
            ans += a
        elif max(a, b, c, d) == b:
            edge[0] = B.pop()
            ans += b
        elif max(a, b, c, d) == c:
            edge[1] = B.popleft()
            ans += c
        else:
            edge[1] = B.pop()
            ans += d
    print(ans)


if __name__ == "__main__":
    main()
