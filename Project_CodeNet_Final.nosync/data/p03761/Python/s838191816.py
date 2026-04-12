def resolve():
    n = int(input())
    s = list(input() for _ in range(n))
    ans = ""
    for i in range(26):
        c = chr(ord('a') + i)
        num = min([si.count(c) for si in s])
        ans += c * num
    print(ans)    


if __name__ == "__main__":
    resolve()
