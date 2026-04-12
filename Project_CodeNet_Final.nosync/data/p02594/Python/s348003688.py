from sys import stdin


def main():
    _in = [_.rstrip() for _ in stdin.readlines()]
    X = int(_in[0])  # type:int
    # vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    ans = 'Yes' if X >= 30 else 'No'
    # ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    print(ans)


if __name__ == "__main__":
    main()
