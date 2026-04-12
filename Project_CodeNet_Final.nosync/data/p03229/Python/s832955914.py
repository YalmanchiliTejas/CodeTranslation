N = int(input())
A = [int(input()) for _ in range(N)]

A.sort()

if N % 2 == 0:  # Nが偶数ならそのままやる
    small = A[:N//2]
    big = A[N//2:]
    ans = sum(big)*2 - sum(small)*2 - big[0] + small[-1]
    print(ans)
else:  # Nが奇数なら中央値くんをsmallに加えるかbig加えるかで議論が起きる
    small = A[:N//2]
    big = A[N//2+1:]
    midian = A[N//2]

    # midianをbigに加えた時, midianを右端に置く
    ans_big = sum(big)*2 - sum(small)*2 - big[0] + midian  # midianを加える代わりにbig[0]とsmall[-1]を救うことができない
    # midianをsmallに加えた時, midianを左端に置く
    ans_small = sum(big)*2 - sum(small)*2 - midian + small[-1]  # midianが引かれる代わりにbig[0]とsmall[-1]を救うことができる
    print(max(ans_big, ans_small))
