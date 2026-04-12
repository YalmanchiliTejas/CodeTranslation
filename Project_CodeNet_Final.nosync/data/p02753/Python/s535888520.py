def A():
    S = input()
    s = "Yes"
    if (S=="AAA") or (S=="BBB"):
        s = "No"
    print(s)
    return s


if __name__ == '__main__':
    A()
