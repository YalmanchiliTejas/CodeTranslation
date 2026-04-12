def main():
    n = int(input())
    s = [input() for i in range(n)]
    seted_s = set(s[0])
    for i in s:
        seted_s = seted_s & set(i)
    from collections import defaultdict
    dicted_s = defaultdict(int)
    for i in seted_s:
        for ss in s:
            dicted_s[i] = min((dicted_s[i] if dicted_s[i] != 0 else 100),ss.count(i))

    ans = ""
    for k,v in dicted_s.items():
        ans = ans + k*v

    print("".join(sorted(ans)))

if __name__ == "__main__":
    main()