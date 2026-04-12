# coding: utf-8
def get_ln_inputs():
    return input().split()


def get_ln_int_inputs():
    return list(map(int, get_ln_inputs()))


def main():
    if int("".join(get_ln_inputs())) % 4 == 0:
        print("YES")
    else:
        print("NO")


main()