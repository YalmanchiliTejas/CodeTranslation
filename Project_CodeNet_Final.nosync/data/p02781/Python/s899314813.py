def main():
    n = input()
    digit = len(n)
    
    k = int(input())
    dp0 = [[0]*k for _ in range(digit)]
    dp0[0][0] = int(n[0])-1
    
    dp1 = [[0]*k for _ in range(digit)]
    dp1[0][0] = 1
    
    c = 1
    flag1 = True
    flag2 = True
    flag3 = False
    flag4 = False
    flag5 = True
    for i in range(1, digit):
        if n[i] != "0":
            c += 1
        for j in range(k):
            if j > i or j > k:
                continue
            if j == 0:
                dp0[i][j] = 9+dp0[i-1][j]
                if c == 1:
                    dp1[i][j] = 1
                else:
                    if flag1:
                        dp0[i][j] += 1
                        flag1 = False
            if j == 1:
                dp0[i][j] = dp0[i-1][j-1]*9+dp0[i-1][j]
                if flag3:
                    dp0[i][j] += dp1[i-1][j-1]*9
                else:
                    dp0[i][j] += dp1[i-1][j-1]*max([(int(n[i])-1), 0])
                    if c >= 2:
                        flag3 = True
                
                if c == 2:
                    dp1[i][j] = 1
                if flag2 and c == 3:
                    dp0[i][j] += 1
                    flag2 = False
                
            if j == 2:
                dp0[i][j] = dp0[i-1][j-1]*9+dp0[i-1][j]
                
                if flag4:
                    dp0[i][j] += dp1[i-1][j-1]*9
                else:
                    dp0[i][j] += dp1[i-1][j-1]*max([(int(n[i])-1), 0])
                    if c >= 3:
                        flag4 = True

                if c == 3:
                    dp1[i][j] = 1
                if flag5 and c == 4:
                    dp0[i][j] += 1
                    flag5 = False
                    
    print(dp0[digit-1][k-1]+dp1[digit-1][k-1])

if __name__ == "__main__":
    main()