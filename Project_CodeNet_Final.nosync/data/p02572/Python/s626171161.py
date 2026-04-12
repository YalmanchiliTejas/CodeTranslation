import sys
read = sys.stdin.buffer.read
readline = sys.stdin.buffer.readline
readlines = sys.stdin.buffer.readlines
 
def main():
    N = int(readline())
    A = [int(i) for i in readline().split()]
    K = int(1e9)+7
    acum = [0]
    for i  in range(N):
        acum.append(acum[i]+A[i])
    ans = 0
    for i in range(N):
        ans += A[i]*(acum[N]-acum[i+1])
        ans %= K
    print(ans)
if __name__ == '__main__':
    main()
