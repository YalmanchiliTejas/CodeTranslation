import sys

def I(): return int(sys.stdin.readline())
def MI(): return map(int, sys.stdin.readline().split())
def LI(): return list(map(int, sys.stdin.readline().split()))
def main():
    s = input()
    for i in range(len(s)-1):
        ans = s[i]+s[i+1]
        if ans == 'AC':
            print('Yes')
            sys.exit()
    print('No')

if __name__ == '__main__':
    main()