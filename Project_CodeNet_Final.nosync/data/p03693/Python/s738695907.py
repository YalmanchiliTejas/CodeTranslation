
def resolve():
    n = int("".join(input().split()))
    print("YES" if n%4==0 else "NO")
    


if '__main__' == __name__:
    resolve()