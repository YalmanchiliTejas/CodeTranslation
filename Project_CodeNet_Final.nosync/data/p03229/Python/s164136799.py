from collections import deque

def main():
    N = int(input())
    A = deque(sorted((int(input()) for i in range(N))))
    dq = deque()
    dq.append(A.popleft())
    for _ in range(N-1):
        a_first = A[0]
        a_last = A[-1]
        dq_first = dq[0]
        dq_last = dq[-1]

        ff = abs(a_first-dq_first)
        fl = abs(a_first-dq_last)
        lf = abs(a_last-dq_first)
        ll = abs(a_last-dq_last)

        comp_list = [ff, fl, lf, ll]
        max_idx = comp_list.index(max(comp_list))
        if max_idx == 0:
            dq.appendleft(A.popleft())
        elif max_idx == 1:
            dq.append(A.popleft())
        elif max_idx == 2:
            dq.appendleft(A.pop())
        else:
            dq.append(A.pop())

    abs_sum = sum([abs(dq[i] - dq[i-1]) for i in range(1, N)])
    print(abs_sum)
if __name__ == "__main__":
    main()