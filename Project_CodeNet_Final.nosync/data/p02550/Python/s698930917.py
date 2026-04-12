import sys

def I(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def main():
    n, x, m = MI()
    a = x
    flag = [False]*(m+1)
    t = 0
    s = []
    idx = 0
    for _ in range(m+1):
        if flag[a]:
            idx = s.index(a)
            break
        flag[a] = True
        s.append(a)
        t += a
        a = (a*a) % m
        if a == 0:
            print(t)
            sys.exit()
    ans = sum(s[0:idx])
    ans += sum(s[idx:])*((n-idx)//(len(s)-idx))
    ans += sum(s[idx:idx+(n-idx)%(len(s)-idx)])
    print(ans)

if __name__ == '__main__':
    main()