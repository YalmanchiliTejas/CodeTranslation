import sys
def input(): return sys.stdin.readline().rstrip()

def main():
    S = input()
    if len(set(list(S))) > 1:
        print('Yes')
    else:
        print('No')

if __name__ == '__main__':
    main()
