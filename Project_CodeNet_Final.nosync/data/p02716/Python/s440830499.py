MOD = 10 ** 9 + 7
INF = 10 ** 20
import sys
input = sys.stdin.readline
sys.setrecursionlimit(100000000)
dy = (-1,0,1,0)
dx = (0,1,0,-1)

def main():
    n = int(input())
    a = list(map(int,input().split()))
    if n%2 == 0:
        ans1 = 0
        ans2 = 0
        for i in range(n):
            if i%2 == 0:
                ans1 += a[i]
            else:
                ans2 += a[i]
        ans = max(ans1,ans2)

        cuml = [0] * (n + 1)
        cumr = [0] * (n + 1)

        for i in range(n):
            if i == 0:
                cuml[i + 1] = a[i]
            else:
                cuml[i + 1] = cuml[i - 1] + a[i]
        
        for i in range(n - 1,-1,-1):
            if i == n - 1:
                cumr[i] = a[i]
            else:
                cumr[i] = cumr[i + 2] + a[i]
        
        for i in range(1,n - 2,2):
                ans = max(ans,cuml[i] + cumr[i + 2])
    
    else:
        cuml = [0] * (n + 1)
        cumr = [0] * (n + 1)
        cumr2 = [0] * (n + 1)

        for i in range(n):
            if i == 0:
                cuml[i + 1] = a[i]
            else:
                cuml[i + 1] = cuml[i - 1] + a[i]
        
        for i in range(n - 1,-1,-1):
            if i == n - 1:
                cumr[i] = a[i]
                cumr2[i] = a[i]
            else:
                cumr[i] = cumr[i + 2] + a[i]
                if i%2 == 1:
                    if i == n - 2:
                        continue
                    if i == n - 4:
                        cumr2[i] = cumr2[i + 3] + a[i]
                    else:
                        cumr2[i] = max(cumr2[i + 2],cumr[i + 3]) + a[i]

        cumr.append(0)
        ans = -INF
        for i in range(n):
            ans = max(ans,cuml[i] + cumr[i + 2])
            if i <= n - 6 and i%2 == 1:
                ans = max(ans,cuml[i] + cumr2[i + 2])
            if i <= n - 4 and i%2 == 1:
                ans = max(ans,cuml[i] + cumr[i + 3])
    
    print(ans)

if __name__ =='__main__':
    main()  
