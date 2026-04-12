from sys import stdin

def solve(n, hs):
    ans = 0
    max_height = hs[0]
    for i, height in enumerate(hs):
        if i == 0 or max_height <= height:
            ans = ans + 1
            max_height = height
    return ans


def main():
    lines = stdin.readlines()
    n = int(lines[0])
    hs = [int(n) for n in lines[1].split(' ')]
    ans = solve(n, hs)
    print(ans)

if __name__ == '__main__':
    main()