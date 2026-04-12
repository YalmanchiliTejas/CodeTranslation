#-*-coding:utf-8-*-
from collections import Counter

def main():
    n = int(input())
    s_list = [input() for _ in range(n)]
    abc_list = [float('inf') for i in range(26)]
    abc = [chr(i) for i in range(ord('a'), ord('a')+26)]

    for i in s_list:
        counter = Counter(i)
        for j in range(26):
            abc_list[j] = min(abc_list[j], counter[abc[j]])
    
    for i in range(26):
        print(abc[i] * abc_list[i], end='')
    print('')



if __name__ == '__main__':
    main()