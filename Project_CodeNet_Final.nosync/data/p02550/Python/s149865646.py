from sys import stdin


def main():
    _in = [_.rstrip() for _ in stdin.readlines()]
    N, X, M = list(map(int, _in[0].split(' ')))  # type:list(int)
    # vvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvvv
    ans = 0
    A = X
    head_list = []
    head = set()
    repeat = set()
    for i in range(N):
        if A in head:
            ind = head_list.index(A)
            repeat = head_list[ind:]
            head = head_list[:ind]
            break
        else:
            head.add(A)
            head_list.append(A)
            A = pow(A, 2, M)

    if len(repeat) == 0:
        ans = sum(head)
    else:
        repeat_time = (N - len(head)) // len(repeat)
        tail_len = N - len(head) - repeat_time * len(repeat)
        ans = sum(head) + sum(repeat) * repeat_time + sum(repeat[:tail_len])
    # ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    print(ans)


if __name__ == "__main__":
    main()
