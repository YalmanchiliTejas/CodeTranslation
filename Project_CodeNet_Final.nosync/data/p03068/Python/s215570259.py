def main():
    N = input()
    S = [str(i) for i in input()]
    K = int(input())

    target_char = S[K - 1]
    result_list = []

    for s in S:
        if target_char != s:
            result_list.append("*")
        else:
            result_list.append(s)

    print("".join(result_list))


if __name__ == '__main__':
    main()
