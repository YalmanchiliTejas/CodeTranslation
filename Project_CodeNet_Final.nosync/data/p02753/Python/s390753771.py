def resolve():
    S = input()
    print("No" if S in ["AAA", "BBB"] else "Yes")

if '__main__' == __name__:
    resolve()