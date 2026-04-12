from sys import stdin


def mod(val):
    res = val % (10 ** 9 + 7)
    if (res < 0):
        res += (10 ** 9 + 7)
    return res


def main():
    _in = [_.rstrip() for _ in stdin.readlines()]
    N = int(_in[0])  # type:int
    A_arr = list(map(int, _in[1].split(' ')))  # type:list(int)
    # vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    A_arr_mod = [0] * len(A_arr)
    for i, a in enumerate(A_arr):
        A_arr_mod[i] = mod(a)

    ans = 0
    cache = sum(A_arr_mod)
    for i in range(N-1):
        cache -= A_arr_mod[i]
        ans += A_arr_mod[i] * cache
        ans = mod(ans)
    # ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    print(ans)


if __name__ == "__main__":
    main()
