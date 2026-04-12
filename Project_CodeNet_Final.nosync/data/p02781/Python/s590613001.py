N = input()
K = int(input())

Nlen = len(N)

def func(N, K):
    Nlen = len(N)
    ans = 0
    if K == 1:
        ans += (Nlen - 1) * 9
        ans += int(N[0])
    if K == 2:
        for i in range(1, Nlen - 1):
            ans += 9 * 9 * i
        ans += (int(N[0]) - 1) * 9 * (Nlen - 1)
        for i in range(1, len(N)):
            if not N[i] == '0':
                ans += func(N[i:], 1)
                break
    if K == 3:
        for i in range(2, Nlen - 1):
            ans += 9 * 81 * i * (i - 1) // 2
        ans += (int(N[0]) - 1) * 81 * (Nlen - 1) * (Nlen - 2) // 2
        for i in range(1, len(N)):
            if not N[i] == '0':
                ans += func(N[i:], 2)
                break
    return ans
    
print(func(N, K))