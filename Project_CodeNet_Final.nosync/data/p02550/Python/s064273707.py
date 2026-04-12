def main():
    n, x, m = map(int, input().split())
    a = x
    a_dict = {a: 0}
    loop_s, loop_e = -1, -1
    res = a

    for _ in range(n-1):
        a = a * a
        a %= m
        if a in a_dict:
            loop_s = a_dict[a]
            loop_e = len(a_dict)
            break
        else:
            a_dict[a] = len(a_dict)
            res += a

    if loop_s != -1:
        a_loop = list(a_dict.keys())[loop_s:]
        l_size = len(a_loop)
        r_size = n - len(a_dict)
        res += (r_size // l_size) * sum(a_loop) + sum(a_loop[:r_size%l_size])

    print(res)
        



if __name__ == "__main__":
    main()