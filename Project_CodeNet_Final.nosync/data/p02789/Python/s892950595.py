def main():
    from sys import stdin, setrecursionlimit
    #setrecursionlimit(10**9)
    #n = int(stdin.readline()[:-1])   
    #r = stdin.readline()[:-1]
    #n = int(stdin.readline()[:-1])   
    #r = [stdin.readline() for i in range(n)]
    #t = [int(stdin.readline()) for i in range(n)]
    #a = list(map(int, r.split()))
    a, b = map(int, input().split())
    #a = [int(s[i]) for i in range(1, n+1)]
    #a = [list(map(int, r.split())) for i in range(1,n+1)]

    cnt = 0
    if a-b == 0:
        print('Yes')
    else:
        print('No')

    #'Yes', 'No', 'YES', 'NO', ':(', 'Yay!'
    #res = 0
    #a, b = map(int, r.split())
    #print()

if __name__ == '__main__':
    main()

