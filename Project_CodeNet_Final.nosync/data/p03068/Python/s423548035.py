if __name__ == '__main__':
    N = int(input())
    S = str(input())
    K = int(input())

    replace_str = S[K-1]
    list_S = list(S)

    for i in range(0, N):
        if list_S[i] == replace_str:
            continue
        else:
            list_S[i] = "*"

    answer = "".join(list_S)
    print(answer)