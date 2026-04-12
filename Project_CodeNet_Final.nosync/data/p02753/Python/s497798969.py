#!python3

iim = lambda: map(int, input().rstrip().split())

def resolve():
    s1, s2, s3 = input()

    print("Yes" if s1 != s2 or s2 != s3 else "No")

if __name__ == "__main__":
    resolve()
