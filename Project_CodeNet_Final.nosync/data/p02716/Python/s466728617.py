from sys import stdin, stdout
def main():
    N = int(stdin.readline())
    A = [0] + list(map(int, stdin.readline().rstrip().split()))
    dp = [0] * (N+1)
    prefix = [0] * (N+1)
    dp[1], prefix[1] = 0, A[1]
    for i in range(3, N, 2):
        prefix[i] = prefix[i-2]+A[i]
    for i in range(2, N+1):
        if i & 1:
            dp[i] = max(dp[i-1], A[i] + dp[i-2])
        else:
            dp[i] = max(dp[i-2] + A[i], prefix[i-1])
    
    stdout.write(str(dp[N])+"\n")
main()
