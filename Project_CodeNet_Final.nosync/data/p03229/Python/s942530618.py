N = int(input())
A = [int(input()) for _ in range(N)]
A = sorted(A)

if N % 2 == 1:
    mid = A[N // 2]
#     print(mid)
    A = sorted([abs(a-mid) for a in A])
#     print(A)
    print(sum(A[:2]) + 2 * sum(A[2:]))

else:
    mid1 = A[N // 2 - 1]
    mid2 = A[N // 2]
    A_ori = [a for a in A]
    
    # 1
    A = [abs(a-mid1) for a in A_ori]
    one = A.pop(N // 2)
    two = A.pop(N // 2 - 1)
    cand = one + two + 2 * sum(A)
    
    # 2
    A = [abs(a-mid2) for a in A_ori]
    one = A.pop(N // 2)
    two = A.pop(N // 2 - 1)
    cand2 = one + two + 2 * sum(A)

#     print(cand, cand2)
    print(max(cand, cand2))