# -*- coding: utf-8 -*-
def main():
    N = int(input())
    A  = [int(i) for i in input().split()]
    #N = 100000
    #A = [i for i in range(1,100000)]
    sum_a = sum(A)% 1000000007
    ans = 0
    for i in range(N):
        sum_a = (sum_a - A[i])% 1000000007
        ans = (ans + sum_a*A[i] ) % 1000000007
        #print((sum_a-A[i])*A[i]/2 ,ans)
    print(ans)
if __name__ == "__main__":
    main()
