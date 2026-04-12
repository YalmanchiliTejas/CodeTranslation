import bisect

def main():
    n = int(input())
    A = list(map(int,input().split()))
    q = int(input())
    for _ in range(q):
        b = int(input())
        index = bisect.bisect_left(A,b)
        print (index)



if __name__ == '__main__':
    main()


