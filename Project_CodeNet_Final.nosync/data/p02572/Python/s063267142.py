import sys

def main():
    input = sys.stdin.readline
    n = int(input())
    a_list = list(map(int, input().split()))
    b_list = [0]*(n+1)
    MOD = 10**9 + 7

    for i in range(n):
        b_list[i+1] = b_list[i] + a_list[i]
    
    ans = 0
    for i in range(n):
        ai_sum = b_list[n] - b_list[i+1]
        ans += ai_sum * a_list[i]
        ans %= MOD
    print(ans)




    


if __name__ == '__main__':
    main()