from collections import deque

def main():
    N = int(input())
    A = deque(sorted((int(input()) for i in range(N))))
    dq = deque()
    dq.append(A.popleft())
    ans = 0
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
            ans += ff
            dq.appendleft(A.popleft())
        elif max_idx == 1:
            ans += fl
            dq.append(A.popleft())
        elif max_idx == 2:
            ans += lf
            dq.appendleft(A.pop())
        else:
            ans += ll
            dq.append(A.pop())

    print(ans)
if __name__ == "__main__":
    main()