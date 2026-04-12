import sys
input = sys.stdin.readline

def main():
    rgb = int(''.join(input().split()))
    print('YES' if rgb % 4 == 0 else 'NO')

main()
