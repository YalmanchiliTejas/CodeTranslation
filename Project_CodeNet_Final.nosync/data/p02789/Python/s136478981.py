from sys import stdin

def main():
    n,m = map(int,stdin.readline().split())
    if(n==m):
        print("Yes")
    else:
        print("No")

main()
