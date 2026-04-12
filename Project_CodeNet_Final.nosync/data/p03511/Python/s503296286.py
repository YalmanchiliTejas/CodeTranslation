def main():
    L = int(input())
    S, T = (input() for _ in [0] * 2)

    ans = []
    apnd = ans.append
    a = S
    b = T
    i = 0
    for _ in [0] * 2:
        while 1:
            x = L - (len(b) * i)
            div_, mod_ = divmod(x, len(a))
            if not mod_:
                apnd(a * div_ + b * i)
                break
            i += 1
        i = 0
        a, b = b, a
    print(min(ans))

main()
