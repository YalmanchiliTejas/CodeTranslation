#!/usr/bin/env python3
def main():
    N, A, M = map(int, input().split())

    ans = 0
    loop = set([A])
    lst = [A]
    for _ in range(N):
        ans += A
        A = pow(A, 2, M)
        if A in loop:
            loop_start = lst.index(A)
            loop_sum = sum(lst[loop_start:])
            loop_length = len(lst[loop_start:])
            a = sum(lst[:loop_start])
            b = loop_sum * ((N - loop_start) // loop_length)
            c = sum(lst[loop_start:loop_start + ((N - loop_start) % loop_length)])
            ans = a + b + c
            break
        else:
            loop.add(A)
            lst.append(A)
    print(ans)


if __name__ == '__main__':
    main()
