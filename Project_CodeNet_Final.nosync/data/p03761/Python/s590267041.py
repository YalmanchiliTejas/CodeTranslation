def main():
    n=int(input())
    s=[[i for i in sorted(list(input().upper()))] for i in range(n)]
    used_min=[51]*26
    alpha2num = lambda c: ord(c) - ord('A')
    num2alpha = lambda c: chr(c + 65)
    for i in s:
        tmp = [0 for i in range(26)]
        for j in i:
            tmp[alpha2num(j)] += 1
        for k in range(26):
            if used_min[k] > tmp[k]:
                used_min[k] = tmp[k]
    for i in range(26):
        for j in range(used_min[i]):
            print(num2alpha(i).lower(),end='')

if __name__ == '__main__':
    main()