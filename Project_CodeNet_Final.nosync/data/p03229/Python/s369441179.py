import sys
input = sys.stdin.buffer.readline

def main():
    N = int(input())
    a = [int(input()) for _ in range(N)]
    a.sort()
    
    if N%2 == 0:
        print(2*sum(a[(N//2):])-a[N//2]-2*sum(a[:(N//2)])+a[N//2-1])
    else:
        x = 2*sum(a[(N//2):])-a[N//2]-a[(N//2)+1]-2*sum(a[:(N//2)])
        y = 2*sum(a[(N//2+1):])-2*sum(a[:(N//2+1)])+a[N//2]+a[N//2-1]
        print(max(x,y))
    
if __name__ == "__main__":
    main()