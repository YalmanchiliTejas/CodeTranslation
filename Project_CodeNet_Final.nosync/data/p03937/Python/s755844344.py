from sys import stdin

def main():
    from collections import deque
    input = stdin.readline

    h, w = map(int, input().split())
    cm = [["."] * (w + 2) for _ in range(h + 2)]
    que = deque([])
    for i in range(1, h + 1):
        cm[i] = "." + input().rstrip('\n') + "."
    que.append([1, 1])
    while len(que) > 0:
        y, x = que.popleft()
        if (cm[y + 1][x] == "#" and cm[y][x + 1] == "#") or cm[y + 1][x - 1] == "#" or cm[y - 1][x + 1] == "#":
            print('Impossible')
            exit()
        if cm[y + 1][x] == "#":
            que.append([y + 1, x])
        if cm[y][x + 1] == "#":
            que.append([y, x + 1])
    print('Possible')
main()