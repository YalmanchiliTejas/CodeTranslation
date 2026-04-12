import sys
input = sys.stdin.readline

def main():
    n = int(input())
    a = list(map(int, input().split()))
    
    sub = 0
    ans = 0
    mod = pow(10, 9)+7
    for i in range(n):
        ans = (ans + sub*a[i])%mod
        sub += a[i]
    
    print(ans)
    
    
    
    
if __name__ == "__main__":
    main()
