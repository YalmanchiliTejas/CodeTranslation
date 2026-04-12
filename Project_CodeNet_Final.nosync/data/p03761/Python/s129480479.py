def input():
    import sys
    return sys.stdin.readline().rstrip()


def main():
    import math
    import collections
    import itertools
    import string

    n = int(input())
    # s = [input() for _ in range(n)]
    a_z = string.ascii_lowercase
    counters = []
    for _ in range(n):
        s = input()
        # print(s)
        tmp_counter = {char: 0 for char in a_z}
        input_counter = collections.Counter(s)
        for char, count in input_counter.items():
            tmp_counter[char] += count
        counters.append(tmp_counter)

    char_common = {}
    for char in a_z:
        char_common[char] = float("INF")
        for counter in counters:
            char_common[char] = min(char_common[char], counter[char])
    
    ans = ''
    for char in a_z:
        ans += char_common[char] * char
    print(ans)

    
if __name__ == '__main__':
    main()