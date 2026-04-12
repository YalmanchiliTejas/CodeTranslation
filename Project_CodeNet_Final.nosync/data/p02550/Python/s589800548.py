def main():
    n,x,m = map(int,input().split())
    if m == 0:
        print(0)
        return
    t = [x]
    k = -1
    for _ in range(n-1):
        x = x**2 % m
        if x in t:
            k = x
            break
        t.append(x)
    if k not in t:
        print(sum(t))
        return
    else:
        s = t.index(k)
        ans = sum(t[0:s])
        b = t[s:len(t)]
        n -= s
        ans += sum(b) * (n//len(b))
        ans += sum(b[0:n%len(b)])
        print(ans)

if __name__ == "__main__":
    main()