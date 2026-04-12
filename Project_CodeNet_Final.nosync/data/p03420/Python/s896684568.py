import sys
input = sys.stdin.readline

def main():
    N,K = map(int,input().split())
    count = 0
    for i in range(K+1,N+1):
        p = N//i
        r = N%i
        count += p*max(0,i-K)+max(0,r-K+1)

    print(count) if K != 0 else print(count-N)

if __name__ == "__main__":
    main()