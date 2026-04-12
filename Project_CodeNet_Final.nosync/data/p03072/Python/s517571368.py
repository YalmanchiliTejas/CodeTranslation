def solve():
    N = int(raw_input())
    H = [int(_) for _ in raw_input().split()]
    MaxH = H[0]
    cnt = 1
    for i in range(1,N):
        if H[i] >= MaxH:
            cnt += 1
            MaxH = H[i]
    print str(cnt)

if __name__ == '__main__':
    solve()
