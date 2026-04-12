def main():
    #from sys import stdin, setrecursionlimit
    #setrecursionlimit(10**9)
    #r = input()
    #n = int(input())
    #a, b = map(int, input().split())
    #s, y = input().split()
    #a = input().split()
    #a = [int(input()) for i in range(n)]
    #a = list(map(int, input().split()))
    #a = [list(map(int, input().split())) for i in range(n)]
    #a = [int(s) - 1 for s in input().split()]
    #l=[int(input()) for _ in range(int(input()))]
    #res = 0
    n = list(map(int,input().split()))
    maisu = max(n[3],n[4])
    ans = [0]*(maisu+1)
    for i in range(maisu+1):
        ans[i] = n[2]*i*2+n[0]*max(0,(n[3]-i))+n[1]*max(0,(n[4]-i))
    print(min(ans))

if __name__ == '__main__':
    main()
