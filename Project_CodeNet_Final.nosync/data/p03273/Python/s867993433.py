from sys import stdin, stdout

input = lambda: stdin.readline().rstrip()
write = stdout.write

def main():
    H, W = map(int, input().split())
    A = stdin.read().splitlines()

    def func(a):
        ret = []
        for s in a:
            if s.count('#'):
                ret.append(s)
        return ret

    ans = func(list(zip(*A)))
    ans = func(list(zip(*ans)))
    for s in ans:
        print(*s, sep='')

main()
