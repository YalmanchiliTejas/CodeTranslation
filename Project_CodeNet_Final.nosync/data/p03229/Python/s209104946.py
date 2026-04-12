N = int(input())
A = [int(input()) for _ in range(N)]
B = sorted(A, reverse=False)
A.sort(reverse=True)

if N == 2:
    print(abs(A[0] - A[1]))
else:
    l_in = 0
    r_in = len(A) - 1
    ans_a = (A[l_in] - A[r_in]) + (A[l_in] - A[r_in - 1])
    hashi = [A[r_in], A[r_in-1]]
    l_in += 1
    r_in -= 2
    while l_in != r_in and N != 3:
        l_max = max(abs(A[l_in] - hashi[0]), abs(A[l_in] - hashi[1]))
        r_max = max(abs(A[r_in] - hashi[0]), abs(A[r_in] - hashi[1]))
        if l_max > r_max:
            if abs(A[l_in] - hashi[0]) > abs(A[l_in] - hashi[1]):
                ans_a += abs(A[l_in] - hashi[0])
                hashi[0] = A[l_in]
            else:
                ans_a += abs(A[l_in] - hashi[1])
                hashi[1] = A[l_in]
            l_in += 1
        else:
            if abs(A[r_in] - hashi[0]) > abs(A[r_in] - hashi[1]):
                ans_a += abs(A[r_in] - hashi[0])
                hashi[0] = A[r_in]
            else:
                ans_a += abs(A[r_in] - hashi[1])
                hashi[1] = A[r_in]
            r_in -= 1
    # last
    if l_in == r_in:
        if abs(A[l_in] - hashi[0]) > abs(A[l_in] - hashi[1]):
            ans_a += abs(A[l_in] - hashi[0])
            hashi[0] = A[l_in]
        else:
            ans_a += abs(A[l_in] - hashi[1])
            hashi[1] = A[l_in]

    l_in = 0
    r_in = len(B) - 1
    ans_b = abs(B[l_in] - B[r_in]) + abs(B[l_in] - B[r_in - 1])
    hashi = [B[r_in], B[r_in - 1]]
    l_in += 1
    r_in -= 2
    while l_in != r_in and N != 3:
        l_max = max(abs(B[l_in] - hashi[0]), abs(B[l_in] - hashi[1]))
        r_max = max(abs(B[r_in] - hashi[0]), abs(B[r_in] - hashi[1]))
        if l_max > r_max:
            if abs(B[l_in] - hashi[0]) > abs(B[l_in] - hashi[1]):
                ans_b += abs(B[l_in] - hashi[0])
                hashi[0] = B[l_in]
            else:
                ans_b += abs(B[l_in] - hashi[1])
                hashi[1] = B[l_in]
            l_in += 1
        else:
            if abs(B[r_in] - hashi[0]) > abs(B[r_in] - hashi[1]):
                ans_b += abs(B[r_in] - hashi[0])
                hashi[0] = B[r_in]
            else:
                ans_b += abs(B[r_in] - hashi[1])
                hashi[1] = B[r_in]
            r_in -= 1
    # last
    if l_in == r_in:
        if abs(B[l_in] - hashi[0]) > abs(B[l_in] - hashi[1]):
            ans_b += abs(B[l_in] - hashi[0])
            hashi[0] = B[l_in]
        else:
            ans_b += abs(B[l_in] - hashi[1])
            hashi[1] = B[l_in]

    print(max(ans_a, ans_b))
