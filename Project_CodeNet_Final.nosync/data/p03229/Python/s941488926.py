def c_align(N, A):
    from collections import deque
    if N == 2:
        return abs(A[0] - A[1])
    tmp = sorted(A)

    seq = tmp[:]
    old_check = seq.pop(-1 + N // 2) if N % 2 == 0 else seq.pop(N // 2)
    current_check = -1
    seq = deque(seq)
    ans1 = 0
    turn = 0
    while seq:
        current_check = seq.pop() if turn % 2 == 0 else seq.popleft()
        ans1 += abs(current_check - old_check)
        old_check = current_check
        turn += 1

    seq = tmp[:]
    old_check = seq.pop(1 + N // 2) if N % 2 == 0 else seq.pop(N // 2)
    current_check = -1
    seq = deque(seq)
    ans2 = 0
    turn = 0
    while seq:
        current_check = seq.popleft() if turn % 2 == 0 else seq.pop()
        ans2 += abs(current_check - old_check)
        old_check = current_check
        turn += 1

    ans = max(ans1, ans2)
    return ans

N = int(input())
A = [int(input()) for _ in range(N)]
print(c_align(N, A))