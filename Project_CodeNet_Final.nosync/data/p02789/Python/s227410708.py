import sys
input = sys.stdin.readline

def main():
    n = list(map(int, input().split()))
    ans = "Yes" if n[0] == n[1] else "No"
    print(ans)
main()
