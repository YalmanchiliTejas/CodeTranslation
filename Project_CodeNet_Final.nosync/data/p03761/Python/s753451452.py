import functools
def slove(s_list):
    char_list = sorted(functools.reduce(set.intersection,
                                        [set(i) for i in s_list]))
    ans = ""
    for c in char_list:
        wc = 51
        for s in s_list:
            wc = min(wc, s.count(c))
        ans += c*wc
    return ans

if __name__ == "__main__":
    n = int(input())
    s = [input() for i in range(n)]
    print(slove(s))
