def main():
    h, w = map(int, input().strip().split())
    S = set(i for i in range(w))
    A = []

    for i in range(h):
        a = input()
        s = set()
        for i in range(w):
            if a[i] == ".":
                s.add(i)
        S = S & s
        if len(s) != w:
            A.append(a)
    
    for word in A:
        print_w = ""
        for i in range(w):
            if not(i in S):
              print_w += word[i]
        print(print_w)

if __name__ == "__main__":
    main()