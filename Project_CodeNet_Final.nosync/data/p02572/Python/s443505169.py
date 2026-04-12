# coding: utf-8

def main():
    n = int(input())
    a_list = list(map(int, input().split()))

    a_sum = sum(a_list)
    ans = 0 
    for i in range(n-1):
        a_head = a_list[i]
        a_sum -=  a_head
        ans += a_head * a_sum
    
    print(ans % (10**9 + 7))
        

main()