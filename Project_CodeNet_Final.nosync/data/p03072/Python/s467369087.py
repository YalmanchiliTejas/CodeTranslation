from sys import stdin

def main():
    N = int(input())
    H = map(int, input().split())

    cnt = 0
    max_ = 0
    for i in H:
        if max_ <= i:
            cnt += 1
            max_ = i
    print(cnt)

input = lambda: stdin.readline()
main()
