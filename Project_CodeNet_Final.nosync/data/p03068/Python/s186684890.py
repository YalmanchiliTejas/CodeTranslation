def main():

    N = int(input())
    S = input()
    K = int(input())
    ref = S[K-1]
    t = ""
    for c in S:
        if c == ref:
            t += ref
        else:
            t += "*"
    return t

if __name__ == '__main__':
    print(main())