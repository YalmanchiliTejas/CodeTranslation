
mod10_9p7 = 10**9 + 7

def main() :

    n = int(input())
    a_list = [int(i) for i in input().split()]

    sop = [0] * (n-1)
    sop[0] = a_list[0]

    for i in range(1,n-1):
        a = a_list[i]
        sop[i] = sop[i-1] + a

    # print(sop)

    res = 0
    # res = (a_list[0] * a_list[1]) % mod10_9p7
    for i in range(n-1) :
        res += (a_list[i+1] * sop[i]) % mod10_9p7
        res = res % mod10_9p7
    
    print(res)
        

main()