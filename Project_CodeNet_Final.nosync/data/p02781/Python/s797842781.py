import sys
from io import StringIO

def resolve():
    s=input().strip()
    k=int(input().strip())

    dp = [[[0 for a in range(2)] for b in range(5)]for c in range(105)]

    #0 same 1 under
    dp[0][0][0]=1

    keta=1
    for a in s:
        for b in range(4):
            for c in range(2): #0 same 1 under
                n=int(a)
                for d in range(10):
                    if c==0 and d > n:
                        #out
                        continue

                    b2 = b
                    if d != 0:
                        b2 += 1
                    
                    c2=c
                    if c==0 and n != d:
                        c2 = 1

                    dp[keta][b2][c2]+=dp[keta-1][b][c]
        keta+=1

    ans = dp[len(s)][k][0] + dp[len(s)][k][1]

    print(ans)

    return

resolve()