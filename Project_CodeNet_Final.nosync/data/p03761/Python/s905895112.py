def main():
    n = int(input())
    ss = [list(input()) for _ in range(n)]

    ss_set = sorted(list(set(ss[0])))
    ans = ''

    for ch in ss_set:
        cnt = min(ss[i].count(ch) for i in range(n))
        ans += ch * cnt
    print(ans)


if __name__ == "__main__":
    main()
