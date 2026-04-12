def solve():
    n = int(input())
    h = list(map(int, input().split()))
    ok = [h[0]]
    for i in range(1, n):
        if max(ok) <= h[i]:
            ok.append(h[i])
    print(len(ok))




if __name__ == '__main__':
    solve()
