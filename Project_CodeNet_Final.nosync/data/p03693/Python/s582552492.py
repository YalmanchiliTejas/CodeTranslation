def main():
    from sys import stdin, setrecursionlimit
    #setrecursionlimit(10**9)
    #n = int(stdin.readline()[:-1])   
    r = stdin.readline()[:-1]
    #n = int(stdin.readline()[:-1])   
    #r = [stdin.readline() for i in range(n)]
    #t = [int(stdin.readline()) for i in range(n)]
    a = r.split()
    #a = list(map(int, r.split()))
    #a, b = map(int, r.split())
    #a = [int(s[i]) for i in range(1, n+1)]
    #a = [list(map(int, r.split())) for i in range(1,n+1)]
    #res = 0

    if int(''.join(a)) % 4 == 0:
        print('YES')
    else:
        print('NO')        

if __name__ == '__main__':
    main()
