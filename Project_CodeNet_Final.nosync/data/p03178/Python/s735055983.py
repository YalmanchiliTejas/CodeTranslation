

def submit():
    k = input()
    lenk = len(k)
    d = int(input())
    f = lambda x: x % d
    modp = 10 ** 9 + 7

    dp = [[[0 for _ in range(d)],
           [0 for _ in range(d)]] for _ in range(lenk)]

    curr = int(k[0])
    for j in range(10):
        if j < curr:
            dp[0][0][f(j)] += 1
        if j == curr:
            dp[0][1][f(j)] += 1
            break

    for i in range(1, lenk):
        curr = int(k[i])
        for s in range(d):
            # smaller at prev
            for j in range(10):
                dp[i][0][f(s + j)] += dp[i - 1][0][s]
                dp[i][0][f(s + j)] %= modp
            
            # unsmall at prev
            for j in range(curr + 1):
                dp[i][j == curr][f(s + j)] += dp[i - 1][1][s]
                dp[i][j == curr][f(s + j)] %= modp
                
    ans = dp[lenk - 1][0][0] + dp[lenk - 1][1][0] - 1
    print(ans % modp)

submit()
            