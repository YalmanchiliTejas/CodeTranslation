def abc058_c():
    from collections import Counter
    n = int(input())
    s = [list(input()) for _ in range(n)]
    s_count = [Counter(s[i]) for i in range(n)]
    ans_dict = {}
    for i in range(ord("a"), ord("z")+1):
        ans_dict[chr(i)] = 50
    for i in range(n):
        for let in ans_dict:
            ans_dict[let] = min(ans_dict[let], s_count[i][let])
    ans = []
    for let in ans_dict:
        ans += ([let] * ans_dict[let])
    print("".join(sorted(ans)))


abc058_c()