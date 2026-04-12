#!python3

iim = lambda: map(int, input().rstrip().split())

def resolve():
    N, M = iim()
    print("Yes" if N == M else "No")


if __name__ == "__main__":
    resolve()
