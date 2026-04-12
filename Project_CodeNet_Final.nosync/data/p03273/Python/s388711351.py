import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    H, W = map(int, input().split())
    a = []
    for _ in range(H):
        w = input()
        if w.count('#') > 0:
            a.append(w)
    ans = [''] * len(a)
    for i in range(W):
        isOK = False
        for s in a:
            if s[i] == '#':
                isOK = True
                break
        if isOK:
            for j, s in enumerate(a):
                ans[j] += s[i]
    print(*ans, sep='\n')

if __name__ == '__main__':
    main()
