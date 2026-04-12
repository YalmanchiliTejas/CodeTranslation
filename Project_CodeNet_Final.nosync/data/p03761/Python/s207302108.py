def main():
    N = int(input())
    cnt = [float("inf")] * 26
    a = ord('a')
    for _ in range(N):
        S = input()
        tmp = [0] * 26
        for c in S:
            tmp[ord(c) - a] += 1
        for i in range(26):
            cnt[i] = min(cnt[i], tmp[i])
    ans = ""
    for i in range(26):
        ans += chr(a + i) * cnt[i]
    print(ans)


if __name__ == "__main__":
    main()
