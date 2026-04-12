import sys
sys.setrecursionlimit(10**6)

def combinations(n, r):
    if n <= 0 or n < r:
        return 0
    if n == r or r == 0:
        return 1
    if r == 1:
        return n
    return combinations(n-1,r-1) + combinations(n-1,r)

def main():
    n = input().rstrip()
    k = int(input())
    if k == 1:
        print((int(n[0]) - 1) + 9 * (len(n) -  1) + 1)
    elif k == 2:
        a = (int(n[0]) - 1) * 9 * (len(n) - 1)
        b = int(combinations(len(n) - 1, 2) * 9*9)
        c = 0
        for i in range(1, len(n)):
            if n[i] != '0':
                c = int(n[i]) + 9 * (max(len(n) - i - 1, 0))
                break
        print(a + b + c)
    elif k == 3:
        a_a = 0
        a_b = 0
        a_c = 0
        for i in range(1, len(n)):
            if n[i] != '0':
                for j in range(i+1, len(n)):
                    if n[j] != '0':
                        a_a = int(n[j]) + 9 * (max(len(n) - j - 1, 0))
                        break
                a_b = (int(n[i]) - 1) * 9 * (max(len(n) - i - 1, 0))
                a_c = combinations(len(n) - i - 1, 2) * 9 * 9
                break
        b = (int(n[0]) - 1) * combinations(len(n) - 1, 2) * 9 * 9
        c = combinations(len(n) - 1, 3) * 9 * 9 * 9
        print((a_a + a_b + a_c) + b + c)

if __name__ == '__main__':
    main()