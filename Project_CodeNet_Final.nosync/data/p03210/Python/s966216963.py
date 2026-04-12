import sys
def input(): return sys.stdin.readline().strip()

def main():
    x=int(input())
    if x in {3,5,7}:
        print('YES')
    else:
        print('NO')

main()