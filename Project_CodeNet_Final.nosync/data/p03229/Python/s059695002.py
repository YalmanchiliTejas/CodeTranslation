from collections import deque

def main():
    N = int(input())
    A = [int(input()) for _ in range(N)]
    A.sort()
    D = deque(A)
    d = D.popleft()
    tmp = deque([d])
    cnt = 0
    while D:
        if cnt % 2 == 0:
            i = D.pop()
            tmp.appendleft(i)
            if D:
                j = D.pop()
                tmp.append(j)
        else:
            i = D.popleft()
            tmp.appendleft(i)
            if D:
                j = D.popleft()
                tmp.append(j)
        cnt += 1

    ans = 0
    for i in range(N-1):
        ans += abs(tmp[i+1] - tmp[i])

    D = deque(A)
    d = D.pop()
    tmp = deque([d])
    cnt = 0
    while D:
        if cnt % 2 == 0:
            i = D.popleft()
            tmp.appendleft(i)
            if D:
                j = D.popleft()
                tmp.append(j)

        else:
            i = D.pop()
            tmp.appendleft(i)
            if D:
                j = D.pop()
                tmp.append(j)
        cnt += 1

    a = 0
    for i in range(N-1):
        a += abs(tmp[i+1] - tmp[i])

    print(max(a,ans))

if __name__ == "__main__":
    main()