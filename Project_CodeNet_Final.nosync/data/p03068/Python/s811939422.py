if __name__ == '__main__':
    n = int(input())
    s = input()
    k = int(input())
    sk = s[k-1]
    anslst = []
    for i in s:
        if sk != i:
            anslst.append("*")
        else:
            anslst.append(sk)
    for a in anslst:
        print(a, end="")
    print("\n")