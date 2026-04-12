from collections import defaultdict, Counter

def main():
    num = int(input())
    hajime = list(input())

    ans = Counter(hajime)

    for i in range(num - 1):
        aaa = Counter(list(input()))
        ans_kari = defaultdict(int)
        for ele in ans.keys():
            if ele in aaa.keys():
                ans_kari[ele] = min(ans[ele], aaa[ele])
        ans = ans_kari

    for i in range(26):
        for j in range(ans[chr(97 + i)]):
            print(chr(97 + i), end='')

    print()



if __name__ == '__main__':
    main()
