def ruisekiwa(l):
    #関数バージョン
    lst = [0]
    s = 0
    for i,v in enumerate(l):
        lst.append(s + v)
        s += v
    return lst

def solve(n,a):
    r = ruisekiwa(a)
    sm = 0
    for i in range(n-1):
        sm += a[i] * (r[-1] - r[i+1])
    return sm % (10**9 + 7)
def solve2(n,a):
    sm = 0
    for i in range(n-1):
        for j in range(i+1,n):
            sm += a[i] * a[j] % (10**9 + 7)
    return sm


def main():
    n = int(input())
    a = list(map(int,input().split()))

    print(solve(n,a))
    #print(solve2(n,a))



if __name__ == '__main__':
    main()
