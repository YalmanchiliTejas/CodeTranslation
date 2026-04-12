#coding:utf-8

from collections import defaultdict

if __name__ == "__main__":
    n = int(raw_input())
    str_list = []
    for i in range(n):
        str_list.append(raw_input())

    min_counts = [1 << 20] * 26

    for string in str_list:
        counts = [0] * 26
        for char in string:
            counts[ord(char) - ord('a')] += 1

        for i, count in enumerate(counts):
            if count < min_counts[i]:
                min_counts[i] = count

    answer = ""
    for i in range(26):
        answer += chr(ord('a') + i) * min_counts[i]

    print answer
