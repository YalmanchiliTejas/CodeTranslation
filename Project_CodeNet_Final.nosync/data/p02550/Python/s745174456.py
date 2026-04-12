def main():
    N, X, M = map(int, input().split())
    l = [X]
    lset = set(l)
    ans = X
    bf = X
    for i in range(N):
        nx = bf**2%M
        if nx in lset:
            break
        ans += nx
        lset.add(nx)
        l.append(nx)
        bf = nx
    st = l.index(nx)
    retry = l[st:]
    remain = N - len(l)
    ans += (remain//len(retry))*sum(retry) + sum(retry[:remain%len(retry)])
    print(ans)

if __name__ == "__main__":
    main()
