def main():
    n = int(input())
    alph = [[0 for _ in range(n)] for _ in range(26)]
    for i in range(n):
        s = input()
        for c in s:
            alph[ord(c)-97][i] += 1

    ans = ""
    for i in range(26):
        if all(alph[i][j] >0 for j in range(n)):
            k = min(alph[i])
            ans += chr(97+i) * k
    return ans


if __name__ == '__main__':
    print(main())