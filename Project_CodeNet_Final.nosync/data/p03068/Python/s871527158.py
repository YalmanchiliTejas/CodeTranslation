import sys

def main():
    N = int(input())
    text = input()
    K = int(input())
    textK = text[K-1]
    ans = ''
    for t in text:
        if t!=textK:
            ans += '*'
        else:
            ans += t
    print(ans)

if __name__ == '__main__':
    main()
