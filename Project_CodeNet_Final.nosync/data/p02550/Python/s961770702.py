def main():
    N, X, M = map(int, input().split())
    ans = X
    pre = X
    cand = [X]
    cnt = 1
    for i in range(N-1):
        now = pre ** 2 % M
        if now in cand:
            cnt += 1
            index = cand.index(now)
            loop = cand[index:]
            L = len(loop)
            amari = (N - cnt + 1) % L
            syou = (N - cnt + 1) // L
            ans += syou * sum(loop)
            ans += sum(loop[:amari])
            break
        else:
            ans += now
            pre = now
            cand.append(now)
            cnt += 1
    print(ans)


if __name__ == "__main__":
    main()