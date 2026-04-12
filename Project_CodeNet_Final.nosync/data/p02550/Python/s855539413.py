def main():
    N, X, M = map(int, input().split())

    n = [-1] * M
    n[X] = 0

    A = X
    history = [X]
    loop_start = -1
    loop_start_num = -1
    for i in range(1, M+2):
        Anext = A*A % M
        if n[Anext] != -1:
            loop_start = n[Anext]
            loop_start_num = Anext
            break
        history.append(Anext)
        n[Anext] = i
        A = Anext

    # print(n, loop_start,loop_start_num, history)
    ans = 0
    for i in range(min(loop_start, N)):
        ans += history[i]
        N -= 1
    
    loop = history[loop_start:]
    loop_len = len(loop)
    sum_loop = sum(loop)
    # print(sum_loop)

    n_loop = N // loop_len
    ans += sum_loop * n_loop
    N -= loop_len * n_loop

    for i in range(N):
        ans += loop[i]
    print(ans)

if __name__ == '__main__':
    main()